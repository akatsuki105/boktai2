	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A4264
	subs r0, #2
	b _080A4266
_080A4264:
	movs r0, #0
_080A4266:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x66
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r4, #0x3a]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, _080A42E8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, [r4, #0x1c]
	ldr r1, _080A42EC @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x23
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r4, #0x6c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x6c]
	ldr r1, _080A42F0 @ =TimeMC_UpdateDone
	adds r0, r4, #0
	bl TimeMC_SetUpdateCallback
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A42E0
	ldr r1, _080A42F4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080A42E0:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A42E8: .4byte 0x03002BE0
_080A42EC: .4byte 0xFFFFFDFF
_080A42F0: .4byte TimeMC_UpdateDone
_080A42F4: .4byte 0xFFFF0000
