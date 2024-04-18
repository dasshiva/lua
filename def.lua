system = {
	x = 90,
	b = function (x)
		print('Hello')
	end,
	n = 2
}

for i=1,getn(system) do
	print(system['x'])
end
