	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	str r1, [sp, #0x30]
	str r2, [sp, #0x34]
	str r3, [sp, #0x38]
	ldr r0, _080AE00C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080AE094
	ldr r2, _080AE010 @ =0x00001324
	adds r0, r7, r2
	ldrh r5, [r0]
	lsls r4, r5, #0x10
	lsrs r3, r4, #0x10
	cmp r3, #0
	bne _080ADFD4
	b _080AE370
_080ADFD4:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE014 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r3, #0x1f
	bls _080AE034
	movs r4, #0x10
	cmp r3, #0x23
	bls _080AE028
	ldr r2, _080AE018 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE01C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080AE020 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _080AE024 @ =0x00001326
	adds r1, r7, r2
	b _080AE04E
	.align 2, 0
_080AE00C: .4byte 0x030046A0
_080AE010: .4byte 0x00001324
_080AE014: .4byte 0x03003E78
_080AE018: .4byte 0x030046B8
_080AE01C: .4byte 0x000003FF
_080AE020: .4byte 0x0203B400
_080AE024: .4byte 0x00001326
_080AE028:
	ldr r3, _080AE030 @ =0x00001326
	adds r1, r7, r3
	movs r0, #5
	b _080AE04E
	.align 2, 0
_080AE030: .4byte 0x00001326
_080AE034:
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne _080AE050
	ldr r0, _080AE088 @ =0x00001326
	adds r1, r7, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080AE050
	subs r0, r2, #1
_080AE04E:
	strh r0, [r1]
_080AE050:
	movs r0, #0x10
	subs r0, r0, r4
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE08C @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r1]
	ldr r1, _080AE088 @ =0x00001326
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x60]
	adds r0, r3, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r0, _080AE090 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080AE37A
	.align 2, 0
_080AE088: .4byte 0x00001326
_080AE08C: .4byte 0x04000052
_080AE090: .4byte 0x00001324
_080AE094:
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, #0x20
	ldr r1, _080AE0E8 @ =0x030043D0
	ldr r2, _080AE0EC @ =0x04000008
	bl CpuSet
	ldr r2, _080AE0F0 @ =0x00001374
	adds r0, r7, r2
	ldrh r3, [r0]
	cmp r3, #0
	beq _080AE0B2
	b _080AE1E8
_080AE0B2:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE0F4 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080AE0F8 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080AE0D2
	strh r3, [r1]
_080AE0D2:
	ldrh r0, [r1]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0x20
	bls _080AE0FC
	ldrh r1, [r1]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	b _080AE0FE
	.align 2, 0
_080AE0E8: .4byte 0x030043D0
_080AE0EC: .4byte 0x04000008
_080AE0F0: .4byte 0x00001374
_080AE0F4: .4byte 0x03003E78
_080AE0F8: .4byte 0x00001324
_080AE0FC:
	lsrs r0, r2, #0x13
_080AE0FE:
	adds r2, r0, #0
	adds r2, #0xc
	movs r0, #0x10
	subs r0, r0, r2
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE1C8 @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r2, _080AE1CC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE1D0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AE1D4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _080AE1D8 @ =0x00001326
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r1, [sp, #0x60]
	adds r0, r1, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r2, _080AE1DC @ =0x00001324
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r5, #3
	ands r5, r0
	cmp r5, #0
	beq _080AE158
	b _080AE37A
_080AE158:
	movs r3, #0xa2
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, sp, #0x10
	ldrh r1, [r0]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080AE1E0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r4, #0x96
	lsls r4, r4, #1
	orrs r0, r4
	ldr r1, _080AE1E4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x96
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	str r5, [sp]
	movs r0, #0x30
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
	b _080AE37A
	.align 2, 0
_080AE1C8: .4byte 0x04000052
_080AE1CC: .4byte 0x030046B8
_080AE1D0: .4byte 0x000003FF
_080AE1D4: .4byte 0x0203B400
_080AE1D8: .4byte 0x00001326
_080AE1DC: .4byte 0x00001324
_080AE1E0: .4byte 0xFFFF0000
_080AE1E4: .4byte 0x0000FFFF
_080AE1E8:
	ldr r0, _080AE348 @ =0x00001324
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AE1F6
	b _080AE370
_080AE1F6:
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r2, _080AE34C @ =0x0203B400
	mov sl, r2
	ldr r4, _080AE350 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080AE354 @ =0x000003FF
	mov r8, r3
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r5, #0xfa
	lsls r5, r5, #1
	adds r1, r5, #0
	bl Mod
	add r1, sp, #0x20
	mov sb, r1
	ldrh r1, [r1]
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _080AE358 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r4]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080AE35C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r4]
	adds r0, #1
	mov r3, r8
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ands r0, r6
	str r0, [sp, #0x28]
	ldr r1, [r4]
	adds r1, #1
	mov r3, r8
	ands r1, r3
	lsls r0, r1, #1
	add r0, sl
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #0x10
	lsls r0, r0, #0x10
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r6
	str r0, [r2, #4]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r3, [r1]
	movs r4, #7
	ands r3, r4
	adds r3, #8
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	bl FUN_080ad2d0
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE360 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [sp, #0x3c]
	ldrh r0, [r1]
	lsrs r2, r0, #2
	movs r0, #0x10
	subs r0, r0, r2
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE364 @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r4, r0
	cmp r4, #0
	bne _080AE312
	ldr r3, _080AE368 @ =0x00001326
	adds r1, r7, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #6
	bgt _080AE312
	adds r0, r2, #1
	strh r0, [r1]
_080AE312:
	ldr r1, _080AE368 @ =0x00001326
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x60]
	adds r0, r3, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r0, _080AE348 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AE37A
	ldr r0, _080AE36C @ =0x03002C58
	ldr r0, [r0]
	movs r1, #9
	bl FUN_080ad204
	b _080AE37A
	.align 2, 0
_080AE348: .4byte 0x00001324
_080AE34C: .4byte 0x0203B400
_080AE350: .4byte 0x030046B8
_080AE354: .4byte 0x000003FF
_080AE358: .4byte 0xFFFF0000
_080AE35C: .4byte 0x0000FFFF
_080AE360: .4byte 0x03003E78
_080AE364: .4byte 0x04000052
_080AE368: .4byte 0x00001326
_080AE36C: .4byte 0x03002C58
_080AE370:
	ldr r0, _080AE38C @ =0x03003E78
	ldr r1, _080AE390 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080AE37A:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AE38C: .4byte 0x03003E78
_080AE390: .4byte 0xFFFFFDFF
