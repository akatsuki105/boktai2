	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r6, r0, #0
	mov r8, r1
	adds r7, r6, #0
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	adds r0, r6, #0
	mov r1, sb
	bl FUN_08022a0c
	ldr r0, _08027830 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _08027834
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r6, r1
	str r2, [r0]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08027844
	.align 2, 0
_08027830: .4byte 0x03002BE0
_08027834:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r6, r4
	str r2, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r6, r5
	str r2, [r0]
_08027844:
	ldr r0, _080278D4 @ =0x0000CB05
	ldr r1, _080278D8 @ =0x0000D3CA
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _08027854
	b _08027E18
_08027854:
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r0, r0, r6
	mov sl, r0
	mov r2, sl
	adds r1, r3, #0
	ldm r1!, {r0, r4, r5}
	stm r2!, {r0, r4, r5}
	ldm r1!, {r0, r4, r5}
	stm r2!, {r0, r4, r5}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	mov r0, sl
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0xee
	lsls r0, r0, #3
	adds r1, r6, r0
	subs r0, #0xf0
	strh r0, [r1]
	ldr r2, _080278DC @ =0x00000772
	adds r1, r6, r2
	movs r0, #0x80
	strh r0, [r1]
	ldr r3, _080278E0 @ =0x00000774
	adds r1, r6, r3
	movs r0, #0xc0
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080278EC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080278E4 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080278E8 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	adds r4, r0, #0
	b _08027914
	.align 2, 0
_080278D4: .4byte 0x0000CB05
_080278D8: .4byte 0x0000D3CA
_080278DC: .4byte 0x00000772
_080278E0: .4byte 0x00000774
_080278E4: .4byte 0xFFFF0000
_080278E8: .4byte 0x0000FFFF
_080278EC:
	ldr r0, _08027940 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08027944 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _08027948 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r4, #0x40
_08027914:
	movs r0, #0x73
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08027950
	bl Script_GetValue
	str r0, [sp, #0x24]
	bl Script_GetValue
	movs r5, #0xef
	lsls r5, r5, #3
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _0802794C @ =0x0000077A
	adds r1, r6, r2
	strh r0, [r1]
	b _08027966
	.align 2, 0
_08027940: .4byte 0x030046A0
_08027944: .4byte 0xFFFF0000
_08027948: .4byte 0x0000FFFF
_0802794C: .4byte 0x0000077A
_08027950:
	movs r3, #0xfa
	lsls r3, r3, #1
	str r3, [sp, #0x24]
	movs r5, #0xef
	lsls r5, r5, #3
	adds r0, r6, r5
	movs r1, #0xa
	strh r1, [r0]
	ldr r1, _080279C4 @ =0x0000077A
	adds r0, r6, r1
	strh r2, [r0]
_08027966:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080279E0
	bl Script_GetValue
	ldr r2, _080279C8 @ =0x0000077E
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xf0
	lsls r3, r3, #3
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _080279CC @ =0x00000782
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080279D0 @ =0x00000784
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080279D4 @ =0x00000786
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #6
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080279D8 @ =0x0000078A
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080279DC @ =0x0000078C
	adds r1, r6, r3
	strh r0, [r1]
	b _08027A1E
	.align 2, 0
_080279C4: .4byte 0x0000077A
_080279C8: .4byte 0x0000077E
_080279CC: .4byte 0x00000782
_080279D0: .4byte 0x00000784
_080279D4: .4byte 0x00000786
_080279D8: .4byte 0x0000078A
_080279DC: .4byte 0x0000078C
_080279E0:
	ldr r5, _08027AA8 @ =0x0000077E
	adds r0, r6, r5
	movs r3, #0x23
	strh r3, [r0]
	movs r1, #0xf0
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0x32
	strh r1, [r0]
	ldr r2, _08027AAC @ =0x00000782
	adds r0, r6, r2
	movs r2, #0x3c
	strh r2, [r0]
	adds r5, #6
	adds r0, r6, r5
	strh r1, [r0]
	ldr r0, _08027AB0 @ =0x00000786
	adds r1, r6, r0
	movs r0, #0xf0
	strh r0, [r1]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r6, r1
	strh r2, [r0]
	ldr r2, _08027AB4 @ =0x0000078A
	adds r1, r6, r2
	movs r0, #0xd
	strh r0, [r1]
	adds r5, #8
	adds r0, r6, r5
	strh r3, [r0]
_08027A1E:
	str r4, [sp]
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	strb r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xab
	adds r3, r3, r7
	mov sl, r3
	strb r0, [r3]
	movs r5, #0x96
	lsls r5, r5, #2
	adds r4, r6, r5
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r1, #2
	str r1, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x1c
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r0, #1
	mov sb, r0
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08022da8
	mov r3, sl
	ldrb r2, [r3]
	cmp r2, #0
	bne _08027A90
	b _08027BAC
_08027A90:
	movs r0, #0x44
	movs r1, #1
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #1
	beq _08027B10
	cmp r1, #1
	bgt _08027AB8
	cmp r1, #0
	beq _08027ABE
	b _08027BF2
	.align 2, 0
_08027AA8: .4byte 0x0000077E
_08027AAC: .4byte 0x00000782
_08027AB0: .4byte 0x00000786
_08027AB4: .4byte 0x0000078A
_08027AB8:
	cmp r1, #2
	beq _08027B60
	b _08027BF2
_08027ABE:
	adds r0, r7, #0
	adds r0, #0xa4
	movs r4, #2
	strb r4, [r0]
	adds r0, #1
	mov r5, r8
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0x16
	mov r1, r8
	str r1, [r0]
	subs r0, #0x14
	mov r2, sb
	strb r2, [r0]
	ldr r1, _08027B0C @ =FUN_08027188
	movs r0, #0x12
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r3, r8
	str r3, [r0]
	adds r0, #0x1d
	mov r4, sb
	strb r4, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r1, r6, r5
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r3, [r0]
	b _08027BF2
	.align 2, 0
_08027B0C: .4byte FUN_08027188
_08027B10:
	adds r0, r7, #0
	adds r0, #0xa4
	movs r2, #2
	strb r2, [r0]
	adds r0, #1
	mov r3, r8
	strb r3, [r0]
	adds r0, #1
	mov r4, sb
	strb r4, [r0]
	adds r0, #0x16
	mov r5, r8
	str r5, [r0]
	subs r0, #0x14
	strb r4, [r0]
	ldr r1, _08027B5C @ =FUN_080271e0
	movs r0, #0x13
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _08027BF2
	.align 2, 0
_08027B5C: .4byte FUN_080271e0
_08027B60:
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	mov r3, r8
	str r3, [r0]
	subs r0, #0x14
	mov r4, sb
	strb r4, [r0]
	ldr r1, _08027BA8 @ =FUN_08027278
	movs r0, #0x14
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r0, r6, r5
	strh r3, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, r8
	b _08027BF0
	.align 2, 0
_08027BA8: .4byte FUN_08027278
_08027BAC:
	movs r1, #0x78
	adds r0, r6, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	mov r3, sb
	strb r3, [r0]
	ldr r4, _08027C44 @ =0x0000055A
	adds r0, r6, r4
	strh r1, [r0]
	ldr r1, _08027C48 @ =FUN_08025654
	adds r0, r7, #0
	adds r0, #0xa3
	strb r3, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r1, r6, r5
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
_08027BF0:
	strh r2, [r0]
_08027BF2:
	ldr r1, _08027C4C @ =FUN_080275f4
	adds r0, r7, #0
	adds r0, #0xfc
	str r1, [r0]
	ldr r1, _08027C50 @ =FUN_080275b0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	movs r3, #0xef
	lsls r3, r3, #3
	adds r4, r6, r3
	ldrh r3, [r4]
	adds r0, r7, #0
	ldr r1, [sp, #0x24]
	adds r2, r1, #0
	bl FUN_08022b2c
	adds r0, r6, #0
	bl FUN_080241e4
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_08024294
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08027C54
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08022fac
	b _08027C5E
	.align 2, 0
_08027C44: .4byte 0x0000055A
_08027C48: .4byte FUN_08025654
_08027C4C: .4byte FUN_080275f4
_08027C50: .4byte FUN_080275b0
_08027C54:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_08027C5E:
	movs r0, #0x41
	bl VM_SeekToKeyword
	adds r4, r7, #0
	adds r4, #0xde
	cmp r0, #0
	beq _08027C8C
	movs r5, #0
	b _08027C80
_08027C70:
	bl Script_GetValue
	lsls r2, r5, #2
	adds r1, r7, #0
	adds r1, #0xe8
	adds r1, r1, r2
	str r0, [r1]
	adds r5, #1
_08027C80:
	cmp r5, #3
	bgt _08027C8C
	bl VM_GetPC
	cmp r0, #0
	bne _08027C70
_08027C8C:
	movs r0, #0x65
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08027CD8
	bl Script_GetValue
	ldr r5, _08027CD0 @ =0x0000078E
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf2
	lsls r2, r2, #3
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08027CD4 @ =0x00000792
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #6
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r1, r6, r2
	str r0, [r1]
	b _08027CFE
	.align 2, 0
_08027CD0: .4byte 0x0000078E
_08027CD4: .4byte 0x00000792
_08027CD8:
	ldr r3, _08027D8C @ =0x0000078E
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	movs r5, #0xf2
	lsls r5, r5, #3
	adds r0, r6, r5
	strh r2, [r0]
	ldr r0, _08027D90 @ =0x00000792
	adds r1, r6, r0
	movs r0, #0x1c
	strh r0, [r1]
	adds r3, #6
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r5, #8
	adds r0, r6, r5
	str r2, [r0]
_08027CFE:
	movs r0, #0x4b
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _08027D94 @ =0x0000079C
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x78
	movs r1, #2
	bl VM_GetKeywordValue
	movs r5, #0
	strb r0, [r4]
	ldr r3, _08027D98 @ =0x00000796
	adds r1, r6, r3
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08024324
	adds r0, r6, #0
	bl FUN_0802378c
	ldr r0, _08027D9C @ =0x000004D4
	adds r4, r6, r0
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0x60
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _08027DA0 @ =0x00001964
	str r0, [sp, #8]
	movs r0, #0x64
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x60
	movs r3, #0x60
	bl FUN_08013ba8
	ldr r1, _08027DA4 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	movs r0, #0x6a
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08027DB4
	bl Script_GetValue
	ldr r3, _08027DA8 @ =0x00000542
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08027DAC @ =0x00000546
	adds r1, r6, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _08027DB0 @ =0x0000077C
	adds r1, r6, r5
	b _08027DCA
	.align 2, 0
_08027D8C: .4byte 0x0000078E
_08027D90: .4byte 0x00000792
_08027D94: .4byte 0x0000079C
_08027D98: .4byte 0x00000796
_08027D9C: .4byte 0x000004D4
_08027DA0: .4byte 0x00001964
_08027DA4: .4byte 0x00001C1B
_08027DA8: .4byte 0x00000542
_08027DAC: .4byte 0x00000546
_08027DB0: .4byte 0x0000077C
_08027DB4:
	ldr r0, _08027E20 @ =0x00000542
	adds r1, r6, r0
	movs r0, #0x96
	strh r0, [r1]
	ldr r2, _08027E24 @ =0x00000546
	adds r1, r6, r2
	movs r0, #0x32
	strh r0, [r1]
	ldr r3, _08027E28 @ =0x0000077C
	adds r1, r6, r3
	movs r0, #3
_08027DCA:
	strh r0, [r1]
	ldr r4, _08027E20 @ =0x00000542
	adds r0, r6, r4
	ldrh r1, [r0]
	ldr r5, _08027E2C @ =0x00000544
	adds r0, r6, r5
	strh r1, [r0]
	ldr r1, _08027E30 @ =0x0000078C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08027E34 @ =0x0000078A
	adds r1, r6, r3
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x1e
	movs r2, #0xf
	bl FUN_08059a1c
	adds r5, #0x28
	adds r1, r6, r5
	str r0, [r1]
	cmp r0, #0
	beq _08027E18
	ldr r1, _08027E38 @ =0x00000792
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08027E3C @ =0x00000794
	adds r1, r6, r3
	ldrh r1, [r1]
	movs r4, #0xf3
	lsls r4, r4, #3
	adds r2, r6, r4
	ldr r2, [r2]
	bl FUN_08058ffc
	cmp r0, #0
	bne _08027E40
_08027E18:
	movs r0, #1
	rsbs r0, r0, #0
	b _08027E66
	.align 2, 0
_08027E20: .4byte 0x00000542
_08027E24: .4byte 0x00000546
_08027E28: .4byte 0x0000077C
_08027E2C: .4byte 0x00000544
_08027E30: .4byte 0x0000078C
_08027E34: .4byte 0x0000078A
_08027E38: .4byte 0x00000792
_08027E3C: .4byte 0x00000794
_08027E40:
	ldr r0, _08027E78 @ =0x03003584
	ldr r0, [r0]
	movs r5, #0x99
	lsls r5, r5, #6
	adds r7, r0, r5
	movs r0, #0xae
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r5, #0xf
_08027E52:
	adds r0, r7, #0
	adds r1, r4, #0
	ldr r2, _08027E7C @ =0x04000008
	bl CpuSet
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _08027E52
	movs r0, #0
_08027E66:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08027E78: .4byte 0x03003584
_08027E7C: .4byte 0x04000008
