	push {lr}
	cmp r0, #1
	beq _0820FF00
	cmp r0, #1
	ble _0820FF0C
	cmp r0, #2
	beq _0820FF04
	cmp r0, #3
	beq _0820FF08
	b _0820FF0C
_0820FF00:
	movs r0, #0x14
	b _0820FF0E
_0820FF04:
	movs r0, #0x27
	b _0820FF0E
_0820FF08:
	movs r0, #0x3b
	b _0820FF0E
_0820FF0C:
	movs r0, #1
_0820FF0E:
	pop {r1}
	bx r1
	.align 2, 0
