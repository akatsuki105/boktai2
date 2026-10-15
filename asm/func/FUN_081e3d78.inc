	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x11
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	ldr r2, _081E3DDC @ =0x00001604
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextPanel_Create
	ldr r2, _081E3DE0 @ =0x00001608
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextPanel_Create
	ldr r2, _081E3DE4 @ =0x0000160C
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _081E3DE8 @ =0x00000BB8
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xc
	bl ClearMemory
	movs r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E3DDC: .4byte 0x00001604
_081E3DE0: .4byte 0x00001608
_081E3DE4: .4byte 0x0000160C
_081E3DE8: .4byte 0x00000BB8
