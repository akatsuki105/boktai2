	push {lr}
	cmp r0, #0
	bne _0824177E
	movs r0, #0
	b _082417C8
_0824177E:
	cmp r0, #5
	bgt _08241786
	movs r0, #1
	b _082417C8
_08241786:
	cmp r0, #0xc
	bgt _0824178E
	movs r0, #2
	b _082417C8
_0824178E:
	cmp r0, #0x16
	bgt _08241796
	movs r0, #3
	b _082417C8
_08241796:
	cmp r0, #0x22
	bgt _0824179E
	movs r0, #4
	b _082417C8
_0824179E:
	cmp r0, #0x31
	bgt _082417A6
	movs r0, #5
	b _082417C8
_082417A6:
	cmp r0, #0x42
	bgt _082417AE
	movs r0, #6
	b _082417C8
_082417AE:
	cmp r0, #0x56
	bgt _082417B6
	movs r0, #7
	b _082417C8
_082417B6:
	cmp r0, #0x6d
	bgt _082417BE
	movs r0, #8
	b _082417C8
_082417BE:
	cmp r0, #0x8b
	ble _082417C6
	movs r0, #0xa
	b _082417C8
_082417C6:
	movs r0, #9
_082417C8:
	pop {r1}
	bx r1
