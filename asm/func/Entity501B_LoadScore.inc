	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081E033C @ =0x03002C68
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _081E0340
	movs r1, #1
	rsbs r1, r1, #0
	b _081E0344
	.align 2, 0
_081E033C: .4byte 0x03002C68
_081E0340:
	movs r0, #0x18
	ldrsh r1, [r1, r0]
_081E0344:
	ldr r0, [r4]
	cmp r0, #0
	bne _081E034E
	movs r0, #0
	b _081E035C
_081E034E:
	lsls r1, r1, #1
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
_081E035C:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r2, r3, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081E0384 @ =0x0000270F
	cmp r0, r1
	bls _081E0370
	strh r1, [r2]
_081E0370:
	ldrh r0, [r2]
	cmp r0, #0
	bne _081E0378
	strh r0, [r2]
_081E0378:
	ldr r1, [r4]
	cmp r1, #0
	bne _081E0388
	movs r1, #1
	rsbs r1, r1, #0
	b _081E038C
	.align 2, 0
_081E0384: .4byte 0x0000270F
_081E0388:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_081E038C:
	ldr r0, [r4]
	cmp r0, #0
	bne _081E0396
	movs r0, #0
	b _081E03A2
_081E0396:
	lsls r1, r1, #2
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
_081E03A2:
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r3, r1
	str r0, [r2]
	ldr r1, _081E03CC @ =0x0000270F
	cmp r0, r1
	ble _081E03B2
	str r1, [r2]
_081E03B2:
	ldr r0, [r2]
	ldr r1, _081E03D0 @ =0xFFFFD8F1
	cmp r0, r1
	bge _081E03BC
	str r1, [r2]
_081E03BC:
	ldr r2, _081E03D4 @ =0x000003BA
	adds r1, r3, r2
	movs r0, #0x5a
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E03CC: .4byte 0x0000270F
_081E03D0: .4byte 0xFFFFD8F1
_081E03D4: .4byte 0x000003BA
