	push {lr}
	ldr r0, _08048D60 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08048D72
	cmp r0, #1
	bgt _08048D64
	cmp r0, #0
	beq _08048D6A
	b _08048D72
	.align 2, 0
_08048D60: .4byte 0x030046A0
_08048D64:
	cmp r0, #5
	beq _08048D6E
	b _08048D72
_08048D6A:
	movs r0, #0
	b _08048D74
_08048D6E:
	movs r0, #3
	b _08048D74
_08048D72:
	movs r0, #1
_08048D74:
	pop {r1}
	bx r1
