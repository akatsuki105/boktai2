	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	bl BgPlttBlender_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _08019268
	ldr r1, [r6, #0x18]
	cmp r1, #0xf
	bls _0801926E
_08019268:
	movs r0, #1
	rsbs r0, r0, #0
	b _08019378
_0801926E:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r5, r6, r0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801929A
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	mov sl, r0
	b _080192A0
_0801929A:
	movs r7, #0
	movs r4, #0
	mov sl, r4
_080192A0:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080192BE
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	str r0, [sp]
	b _080192C8
_080192BE:
	movs r0, #0
	mov sb, r0
	mov r8, r0
	movs r1, #0
	str r1, [sp]
_080192C8:
	movs r0, #0x62
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080192E0
	bl Script_GetValue
	str r0, [sp, #4]
	bl Script_GetValue
	adds r3, r0, #0
	b _080192E6
_080192E0:
	movs r0, #0
	str r0, [sp, #4]
	movs r3, #0
_080192E6:
	mov r1, sl
	cmp r1, #1
	bne _08019300
	lsls r0, r7, #4
	adds r0, r0, r4
	lsls r0, r0, #1
	adds r0, #0x1c
	adds r0, r6, r0
	str r0, [r5]
	ldr r2, _080192FC @ =0x03004250
	b _0801930C
	.align 2, 0
_080192FC: .4byte 0x03004250
_08019300:
	lsls r0, r7, #5
	lsls r1, r4, #1
	ldr r2, _08019324 @ =0x03004250
	adds r1, r1, r2
	adds r0, r0, r1
	str r0, [r5]
_0801930C:
	ldr r4, [sp]
	cmp r4, #1
	bne _08019328
	mov r1, sb
	lsls r0, r1, #4
	add r0, r8
	lsls r0, r0, #1
	adds r0, #0x1c
	adds r0, r6, r0
	str r0, [r5, #4]
	b _08019336
	.align 2, 0
_08019324: .4byte 0x03004250
_08019328:
	mov r4, sb
	lsls r1, r4, #5
	mov r4, r8
	lsls r0, r4, #1
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r5, #4]
_08019336:
	ldr r0, [sp, #4]
	lsls r1, r0, #5
	lsls r0, r3, #1
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r5, #8]
	movs r0, #0x6e
	movs r1, #1
	bl VM_GetKeywordValue
	movs r4, #0
	strb r0, [r5, #0xc]
	strb r4, [r5, #0xd]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0xe]
	strb r4, [r5, #0xf]
	movs r0, #0x53
	movs r1, #0xa
	bl VM_GetKeywordValue
	strb r0, [r5, #0x10]
	movs r0, #0x44
	movs r1, #0xa
	bl VM_GetKeywordValue
	adds r1, r0, #0
	strb r1, [r5, #0x11]
	ldr r1, [r6, #0x18]
	adds r1, #1
	str r1, [r6, #0x18]
_08019378:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
