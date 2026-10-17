	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _080CE440 @ =0x000004C4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #1
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl Eff082473e0Emitter_Init
	ldr r2, _080CE444 @ =0x000005FC
	adds r1, r5, r2
	ldr r2, [r4]
	ldr r3, [r4, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r3, _080CE448 @ =0x00000604
	adds r0, r5, r3
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	ldr r2, _080CE44C @ =0x0000060C
	adds r0, r5, r2
	movs r2, #0
	bl ParticleShadow_Init
	bl Entity080dc44c_Create
	adds r0, r5, #0
	bl FUN_080cdc10
	adds r0, r5, #0
	bl FUN_080cc71c
	adds r0, r5, #0
	bl FUN_080cc8e0
	adds r0, r5, #0
	bl FUN_080cd098
	adds r0, r5, #0
	bl FUN_080cd548
	adds r0, r5, #0
	bl FUN_080cce70
	ldr r3, _080CE450 @ =0x0000097C
	adds r0, r5, r3
	movs r1, #4
	strb r1, [r0]
	ldr r2, _080CE454 @ =0x0000097D
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	adds r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080CE458 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE45C
	subs r1, #5
	b _080CE460
	.align 2, 0
_080CE440: .4byte 0x000004C4
_080CE444: .4byte 0x000005FC
_080CE448: .4byte 0x00000604
_080CE44C: .4byte 0x0000060C
_080CE450: .4byte 0x0000097C
_080CE454: .4byte 0x0000097D
_080CE458: .4byte 0x03002C68
_080CE45C:
	movs r3, #0x18
	ldrsh r1, [r0, r3]
_080CE460:
	ldr r0, [r5, #0x18]
	cmp r0, r1
	bne _080CE474
	ldr r0, _080CE470 @ =0x00000978
	adds r1, r5, r0
	movs r0, #0
	b _080CE47A
	.align 2, 0
_080CE470: .4byte 0x00000978
_080CE474:
	ldr r2, _080CE4B4 @ =0x00000978
	adds r1, r5, r2
	movs r0, #1
_080CE47A:
	strb r0, [r1]
	movs r3, #0x97
	lsls r3, r3, #4
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080CE4B8 @ =0x00000972
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	ldr r0, _080CE4BC @ =0x03002BAC
	strh r1, [r0]
	ldr r0, _080CE4C0 @ =0x03002B90
	strh r1, [r0]
	ldr r2, _080CE4C4 @ =0x03002B84
	movs r0, #1
	strh r0, [r2]
	ldr r0, _080CE4C8 @ =0x03002BF0
	strh r1, [r0]
	ldr r0, _080CE4CC @ =0x000003FF
	adds r1, r5, r0
	movs r0, #0xff
	strb r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE4B4: .4byte 0x00000978
_080CE4B8: .4byte 0x00000972
_080CE4BC: .4byte 0x03002BAC
_080CE4C0: .4byte 0x03002B90
_080CE4C4: .4byte 0x03002B84
_080CE4C8: .4byte 0x03002BF0
_080CE4CC: .4byte 0x000003FF
