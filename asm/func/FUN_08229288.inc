	push {lr}
	ldr r2, _082292A4 @ =0x085B00C4
	ldr r3, _082292A8 @ =0x00000F16
	adds r1, r0, r3
	ldrh r1, [r1]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_082292A4: .4byte 0x085B00C4
_082292A8: .4byte 0x00000F16
