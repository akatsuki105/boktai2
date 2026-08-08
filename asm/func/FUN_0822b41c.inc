	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, _0822B45C @ =0x03003A38
	movs r0, #0
	str r0, [r1]
	ldr r4, _0822B460 @ =0x03003A3C
	ldr r5, _0822B464 @ =0x03003E40
	ldr r1, _0822B468 @ =0x03003A30
	movs r2, #0
	adds r0, r1, #6
_0822B430:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0822B430
	movs r0, #0
	str r0, [r4]
	str r0, [r5]
	cmp r3, #0
	beq _0822B454
	ldr r1, _0822B46C @ =0x03003630
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0x7f
_0822B44A:
	str r2, [r1]
	adds r1, #8
	subs r0, #1
	cmp r0, #0
	bge _0822B44A
_0822B454:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822B45C: .4byte 0x03003A38
_0822B460: .4byte 0x03003A3C
_0822B464: .4byte 0x03003E40
_0822B468: .4byte 0x03003A30
_0822B46C: .4byte 0x03003630
