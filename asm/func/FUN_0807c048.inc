	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #2
	bne _0807C078
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r0, _0807C07C @ =0x00000519
	cmp r1, r0
	bne _0807C078
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r2, r1
	str r3, [r0]
	ldr r0, _0807C080 @ =0x0000037D
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_0807b7a4
_0807C078:
	pop {r0}
	bx r0
	.align 2, 0
_0807C07C: .4byte 0x00000519
_0807C080: .4byte 0x0000037D
