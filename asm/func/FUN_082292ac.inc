	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08223748
	ldr r1, _082292D0 @ =0x085B0100
	ldr r2, _082292D4 @ =0x00000F16
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1a
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082292D0: .4byte 0x085B0100
_082292D4: .4byte 0x00000F16
