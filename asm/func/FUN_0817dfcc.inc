	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	ldr r3, _0817DFF0 @ =0x000007A4
	adds r2, r0, r3
	movs r3, #1
	rsbs r3, r3, #0
_0817DFE0:
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r3
	beq _0817DFF4
	adds r0, r1, #0
	b _0817DFFE
	.align 2, 0
_0817DFF0: .4byte 0x000007A4
_0817DFF4:
	adds r1, #1
	cmp r1, #2
	ble _0817DFE0
	movs r0, #1
	rsbs r0, r0, #0
_0817DFFE:
	pop {r1}
	bx r1
	.align 2, 0
