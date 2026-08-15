	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r7, r6, r0
	movs r1, #1
	mov r8, r1
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _08213DEC
	movs r0, #1
_08213DEC:
	movs r3, #2
	rsbs r3, r3, #0
	mov sb, r3
	ands r1, r3
	str r1, [r6, #0x44]
	cmp r0, #0
	beq _08213E6C
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r5, #6
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #6
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r5, [r6, #0x64]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r3, #0xeb
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
_08213E6C:
	ldr r4, [r6, #0x5c]
	cmp r4, #2
	bne _08213E74
	b _08214036
_08213E74:
	cmp r4, #2
	bgt _08213E84
	cmp r4, #0
	beq _08213E98
	cmp r4, #1
	bne _08213E82
	b _08213FDC
_08213E82:
	b _08214152
_08213E84:
	cmp r4, #4
	bne _08213E8A
	b _082140D8
_08213E8A:
	cmp r4, #4
	bge _08213E90
	b _0821407C
_08213E90:
	cmp r4, #0x63
	bne _08213E96
	b _082140FC
_08213E96:
	b _08214152
_08213E98:
	movs r2, #2
	ldr r1, [r6, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08213EA4
	movs r2, #1
_08213EA4:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	cmp r2, #0
	beq _08213EB6
	adds r0, r6, #0
	bl FUN_08213d90
_08213EB6:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	bne _08213EF6
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r1, r1, r0
	ldr r2, [r1]
	adds r0, r2, #0
	mov r3, r8
	ands r0, r3
	cmp r0, #0
	beq _08213EF0
	mov r0, sb
	ands r2, r0
	b _08213EF4
_08213EF0:
	mov r3, r8
	orrs r2, r3
_08213EF4:
	str r2, [r1]
_08213EF6:
	adds r4, r7, #0
	adds r4, #0xc8
	ldrh r0, [r4]
	movs r1, #0xb4
	bl Mod
	adds r5, r0, #0
	mov r8, r4
	cmp r5, #0
	bne _08213F80
	ldr r0, [r6, #0x64]
	cmp r0, #6
	bne _08213F48
	movs r4, #7
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #7
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r4, [r6, #0x64]
	adds r1, r7, #0
	adds r1, #0xc4
	ldr r0, [r1]
	movs r2, #1
	subs r0, r2, r0
	str r0, [r1]
	ldr r0, [r7, #8]
	orrs r0, r2
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08213F7E
_08213F48:
	movs r4, #6
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #6
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r4, [r6, #0x64]
	adds r1, r7, #0
	adds r1, #0xc4
	ldr r0, [r1]
	movs r2, #1
	subs r0, r2, r0
	str r0, [r1]
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	orrs r0, r2
_08213F7E:
	str r0, [r7, #0x68]
_08213F80:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08213FB8 @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08213FBC
	ldr r0, [r6, #0x60]
	cmp r0, #0xf
	ble _08213FBC
	str r3, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	movs r1, #2
	ldr r0, [r6, #0x44]
	orrs r0, r1
	str r0, [r6, #0x44]
	b _08214152
	.align 2, 0
_08213FB8: .4byte 0x030044E0
_08213FBC:
	ldrh r1, [r2, #2]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08213FCA
	b _08214152
_08213FCA:
	ldr r0, [r6, #0x40]
	cmp r0, #1
	beq _08213FD2
	b _08214152
_08213FD2:
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #0x63
	b _082140CA
_08213FDC:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08213FEA
	movs r1, #1
_08213FEA:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08214014
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r1, r1, r0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
_08214014:
	ldr r0, [r6, #0x60]
	cmp r0, #0x3b
	bgt _08214032
	bl FUN_082416d4
	cmp r0, #0
	bne _08214024
	b _08214152
_08214024:
	ldr r0, [r6, #0x40]
	cmp r0, #0
	beq _0821402E
	bl FUN_082410bc
_0821402E:
	str r4, [r6, #0x5c]
	b _082140CC
_08214032:
	movs r0, #3
	b _082140CA
_08214036:
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08214042
	movs r1, #1
_08214042:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082140C8
	movs r0, #0
	bl FUN_0822b644
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl FUN_08047864
	movs r0, #1
	bl FUN_08047a28
	movs r0, #0x28
	movs r1, #5
	movs r2, #0x18
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #0xdd
	b _082140C4
_0821407C:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _0821408A
	movs r1, #1
_0821408A:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082140C8
	movs r0, #0
	bl FUN_0822b644
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl FUN_08047864
	movs r0, #2
	bl FUN_08047a28
	movs r0, #0x26
	movs r1, #5
	movs r2, #0x18
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #0xc9
	lsls r0, r0, #1
_082140C4:
	bl PlaySound_082406e0
_082140C8:
	movs r0, #4
_082140CA:
	str r0, [r6, #0x5c]
_082140CC:
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	b _08214152
_082140D8:
	movs r3, #2
	ldr r2, [r6, #0x44]
	adds r0, r2, #0
	ands r0, r3
	movs r1, #3
	rsbs r1, r1, #0
	ands r1, r2
	str r1, [r6, #0x44]
	ldr r0, [r6, #0x60]
	cmp r0, #0x3b
	ble _08214152
	movs r0, #0x63
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	orrs r1, r3
	str r1, [r6, #0x44]
	b _08214152
_082140FC:
	movs r2, #2
	ldr r1, [r6, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214108
	movs r2, #1
_08214108:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	cmp r2, #0
	beq _0821412C
	movs r0, #0
	bl FUN_0822b644
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl FUN_08047864
_0821412C:
	ldr r0, [r7, #8]
	mov r3, r8
	orrs r0, r3
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	orrs r0, r3
	str r0, [r7, #0x68]
	ldr r0, [r6, #0x40]
	cmp r0, #0
	bne _0821414A
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08219f34
	b _08214152
_0821414A:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08219f34
_08214152:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
