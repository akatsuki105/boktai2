	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	adds r7, r1, #0
	adds r1, r2, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	cmp r1, #0
	beq _081917A6
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	bl Mod
	cmp r0, #0
	beq _081917A6
	b _081919FE
_081917A6:
	lsls r3, r7, #3
	adds r2, r3, r7
	lsls r2, r2, #3
	adds r2, r2, r7
	lsls r2, r2, #2
	add r2, sl
	ldr r1, _081917E4 @ =0x00000674
	adds r0, r2, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r0, _081917E8 @ =0x00000754
	adds r2, r2, r0
	add r5, sp, #0x38
	ldrb r6, [r2]
	ldr r2, _081917EC @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	str r3, [sp, #0x48]
	cmp r0, #0
	blt _081917F0
	asrs r1, r0, #0xc
	b _081917F6
	.align 2, 0
_081917E4: .4byte 0x00000674
_081917E8: .4byte 0x00000754
_081917EC: .4byte gSineTable
_081917F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081917F6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08191814 @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08191818
	asrs r0, r0, #0xc
	b _0819181E
	.align 2, 0
_08191814: .4byte gSineTable
_08191818:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819181E:
	movs r3, #0
	strh r0, [r5, #4]
	add r1, sp, #0x38
	add r6, sp, #0x40
	ldrh r0, [r6]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r2, _081918DC @ =0xFFFF0000
	ldr r1, _081918E0 @ =0x00000472
	add r1, sb
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x40]
	add r1, sp, #0x38
	ldrh r0, [r6, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r6, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r6, #4]
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #0x48]
	adds r4, r0, r7
	lsls r4, r4, #3
	adds r4, r4, r7
	lsls r4, r4, #2
	add r4, sl
	ldr r1, _081918E4 @ =0x00000754
	adds r1, r1, r4
	mov r8, r1
	ldrb r0, [r1]
	adds r0, #0x80
	movs r5, #0xff
	ands r0, r5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x32
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r0, _081918E8 @ =0x0000F422
	str r0, [sp, #0x24]
	ldr r0, _081918EC @ =0x0000121B
	str r0, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r0, #0xda
	str r0, [sp, #0x34]
	adds r0, r6, #0
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl Entity081ee7a8_SpawnEx
	ldr r2, _081918F0 @ =0x00000674
	adds r4, r4, r2
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	mov r1, r8
	ldrb r0, [r1]
	adds r2, r0, #0
	adds r2, #0x40
	add r3, sp, #0x38
	ands r2, r5
	ldr r1, _081918F4 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _081918F8
	asrs r1, r0, #0xc
	b _081918FE
	.align 2, 0
_081918DC: .4byte 0xFFFF0000
_081918E0: .4byte 0x00000472
_081918E4: .4byte 0x00000754
_081918E8: .4byte 0x0000F422
_081918EC: .4byte 0x0000121B
_081918F0: .4byte 0x00000674
_081918F4: .4byte gSineTable
_081918F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081918FE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0819191C @ =gSineTable
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08191920
	asrs r0, r0, #0xc
	b _08191926
	.align 2, 0
_0819191C: .4byte gSineTable
_08191920:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08191926:
	strh r0, [r3, #4]
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r0, [r6]
	adds r1, r1, r0
	add r0, sp, #0x40
	strh r1, [r0]
	ldr r1, _08191994 @ =0x00000472
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0, #2]
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r0, #4]
	adds r1, r1, r2
	strh r1, [r0, #4]
	mov r1, sb
	ldrb r2, [r1, #5]
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r2, [sp, #0x48]
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, sl
	ldr r2, _08191998 @ =0x00000674
	adds r1, r0, r2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	ldr r1, _0819199C @ =0x00000754
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r0, #0
	subs r3, #0x40
	movs r1, #0xff
	add r4, sp, #0x38
	ands r3, r1
	ldr r2, _081919A0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _081919A4
	asrs r1, r0, #0xc
	b _081919AA
	.align 2, 0
_08191994: .4byte 0x00000472
_08191998: .4byte 0x00000674
_0819199C: .4byte 0x00000754
_081919A0: .4byte gSineTable
_081919A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081919AA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081919C8 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081919CC
	asrs r0, r0, #0xc
	b _081919D2
	.align 2, 0
_081919C8: .4byte gSineTable
_081919CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081919D2:
	strh r0, [r4, #4]
	add r0, sp, #0x38
	ldrh r1, [r0]
	ldrh r6, [r6]
	adds r1, r1, r6
	add r0, sp, #0x40
	strh r1, [r0]
	ldr r1, _08191A10 @ =0x00000472
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0, #2]
	add r1, sp, #0x38
	ldrh r1, [r1, #4]
	ldrh r2, [r0, #4]
	adds r1, r1, r2
	strh r1, [r0, #4]
	mov r1, sb
	ldrb r2, [r1, #5]
	movs r1, #1
	movs r3, #1
	bl FUN_08192ae0
_081919FE:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191A10: .4byte 0x00000472
