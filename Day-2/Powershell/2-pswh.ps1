$v = Get-Content -Path 'Day-2\input.txt'

$x = 0
$y = 0
$aim = 0

foreach($c in $v){
    [int]$num = [convert]::ToInt32(($c[$c.Length-1]), 10)
    switch($c[0]){
        "d" { $aim += $num }
        "u" { $aim -= $num }
        "f" { 
                $x += $num
                $y += ($aim * $num)
            }
    }
}

Write-Host $($x * $y)
