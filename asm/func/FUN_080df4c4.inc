	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
_080DF4D0:
	movs r0, #0x5c
	mov r5, r8
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0x3c
	adds r4, r7, r4
	adds r6, r4, #0
	adds r6, #0x2c
	adds r0, r6, #0
	ldr r1, _080DF530 @ =0x0000354D
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r6, #0
	ldr r1, _080DF534 @ =0x00000272
	bl FUN_0822b20c
	adds r0, r7, #0
	adds r0, #0x3c
	adds r0, r0, r5
	ldr r1, _080DF538 @ =0x00000201
	str r1, [r0]
	adds r5, r7, r5
	adds r5, #0x94
	movs r1, #0
	strh r1, [r5]
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #1
	ble _080DF4D0
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, _080DF53C @ =0x000001A3
	adds r1, r7, r0
	movs r0, #2
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DF530: .4byte 0x0000354D
_080DF534: .4byte 0x00000272
_080DF538: .4byte 0x00000201
_080DF53C: .4byte 0x000001A3
