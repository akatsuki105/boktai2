	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov r8, r0
	movs r0, #0
	str r0, [sp, #0x34]
	ldr r0, _080967E4 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080967E8
	movs r0, #0
	b _08096802
	.align 2, 0
_080967E4: .4byte 0x030046A0
_080967E8:
	ldr r0, _08096828 @ =0x00003FDC
	add r0, r8
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, _0809682C @ =0x00003FE0
	add r0, r8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _08096830 @ =0x08DAA7B0
	adds r0, r0, r1
_08096802:
	bl FUN_0807a70c
	adds r7, r0, #0
	ldr r1, _08096834 @ =0x00003AEB
	add r1, r8
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _08096822
	ldr r0, _0809682C @ =0x00003FE0
	add r0, r8
	ldrb r1, [r1]
	adds r1, r0, r1
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08096838
_08096822:
	adds r6, r7, #0
	b _0809684C
	.align 2, 0
_08096828: .4byte 0x00003FDC
_0809682C: .4byte 0x00003FE0
_08096830: .4byte 0x08DAA7B0
_08096834: .4byte 0x00003AEB
_08096838:
	movs r0, #1
	str r0, [sp, #0x34]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #3
	ldr r1, _08096878 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	adds r6, r0, #0
_0809684C:
	cmp r6, r7
	bne _08096880
	movs r2, #1
	ldr r1, _0809687C @ =0x0000216C
	add r1, r8
	movs r5, #2
_08096858:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08096858
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x64
	movs r2, #6
	movs r3, #6
	bl FUN_0808b30c
	b _08096908
	.align 2, 0
_08096878: .4byte 0x08DAA7B0
_0809687C: .4byte 0x0000216C
_08096880:
	movs r0, #6
	movs r1, #6
	movs r2, #3
	movs r3, #1
	bl FUN_0808b97c
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	add r5, sp, #0x28
	str r0, [sp, #0x28]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	subs r4, r6, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	movs r1, #0x14
	mov sl, r1
	adds r0, r5, #0
	cmp r6, r7
	ble _080968C2
	movs r1, #0xa
	mov sl, r1
_080968C2:
	movs r5, #0
	movs r1, #0x60
	add r1, r8
	mov sb, r1
	str r0, [sp, #0x3c]
	ldr r4, _0809692C @ =0x0000216C
	add r4, r8
	ldr r6, _08096930 @ =0x00002164
	add r6, r8
	movs r7, #0x30
_080968D6:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	strh r7, [r4, #0x18]
	movs r0, #0x30
	strh r0, [r4, #0x1a]
	ldr r0, [sp, #0x3c]
	ldm r0!, {r2}
	str r0, [sp, #0x3c]
	add r2, sl
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #8
	adds r5, #1
	cmp r5, #2
	ble _080968D6
_08096908:
	ldr r0, _08096934 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #4
	bl FUN_08242b28
	add r0, sp, #4
	bl FUN_0807a6cc
	adds r7, r0, #0
	ldr r0, [sp, #0x34]
	cmp r0, #0
	bne _08096938
	adds r6, r7, #0
	b _08096956
	.align 2, 0
_0809692C: .4byte 0x0000216C
_08096930: .4byte 0x00002164
_08096934: .4byte 0x030046A0
_08096938:
	ldr r1, _08096984 @ =0x00003AEB
	add r1, r8
	ldr r0, _08096988 @ =0x00003FE0
	add r0, r8
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #3
	ldr r0, _0809698C @ =0x08DAA7B0
	adds r1, r1, r0
	add r0, sp, #4
	bl FUN_0807a5d8
	adds r6, r0, #0
_08096956:
	cmp r6, r7
	bne _08096994
	movs r2, #1
	ldr r1, _08096990 @ =0x0000228C
	add r1, r8
	movs r5, #2
_08096962:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08096962
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x64
	movs r2, #6
	movs r3, #5
	bl FUN_0808b30c
	b _08096A1C
	.align 2, 0
_08096984: .4byte 0x00003AEB
_08096988: .4byte 0x00003FE0
_0809698C: .4byte 0x08DAA7B0
_08096990: .4byte 0x0000228C
_08096994:
	movs r0, #6
	movs r1, #5
	movs r2, #3
	movs r3, #1
	bl FUN_0808b97c
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	add r5, sp, #0x28
	str r0, [sp, #0x28]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	subs r4, r6, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	movs r1, #0x14
	mov sl, r1
	adds r0, r5, #0
	cmp r6, r7
	ble _080969D6
	movs r1, #0xa
	mov sl, r1
_080969D6:
	movs r5, #0
	movs r1, #0x60
	add r1, r8
	mov sb, r1
	str r0, [sp, #0x38]
	ldr r4, _08096A2C @ =0x0000228C
	add r4, r8
	ldr r6, _08096A30 @ =0x00002284
	add r6, r8
	movs r7, #0x30
_080969EA:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	strh r7, [r4, #0x18]
	movs r0, #0x28
	strh r0, [r4, #0x1a]
	ldr r0, [sp, #0x38]
	ldm r0!, {r2}
	str r0, [sp, #0x38]
	add r2, sl
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #8
	adds r5, #1
	cmp r5, #2
	ble _080969EA
_08096A1C:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096A2C: .4byte 0x0000228C
_08096A30: .4byte 0x00002284
