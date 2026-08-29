	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	str r1, [sp, #0x28]
	mov r8, r7
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x74
	bl Script_GetKeywordValue
	adds r6, r0, #0
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08022a0c
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08221D70
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08221D68 @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08221D6C @ =0x0000FFFF
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r4, sp, #0x20
	ldr r1, [r4, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r4, #4]
	bl Script_GetValue
	adds r5, r0, #0
	mov sl, r4
	b _08221D80
	.align 2, 0
_08221D68: .4byte 0xFFFF0000
_08221D6C: .4byte 0x0000FFFF
_08221D70:
	ldr r2, _08221DAC @ =0xFFFF0000
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
	mov sl, r1
_08221D80:
	movs r0, #0x72
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08221DBC
	bl Script_GetValue
	ldr r2, _08221DB0 @ =0x00000BC4
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221DB4 @ =0x00000BC6
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221DB8 @ =0x00000BC8
	adds r1, r7, r2
	strh r0, [r1]
	b _08221DCE
	.align 2, 0
_08221DAC: .4byte 0xFFFF0000
_08221DB0: .4byte 0x00000BC4
_08221DB4: .4byte 0x00000BC6
_08221DB8: .4byte 0x00000BC8
_08221DBC:
	ldr r2, _08221DFC @ =0x00000BC4
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
_08221DCE:
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [sp, #0x20]
	asrs r1, r1, #0x10
	str r1, [r0]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08221E04
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	ldr r2, _08221E00 @ =0x000003EA
	adds r1, r7, r2
	b _08221E14
	.align 2, 0
_08221DFC: .4byte 0x00000BC4
_08221E00: .4byte 0x000003EA
_08221E04:
	movs r4, #0xfa
	lsls r4, r4, #2
	ldr r0, _08221E54 @ =0x000003E7
	mov sb, r0
	ldr r2, _08221E58 @ =0x000003EA
	adds r1, r7, r2
	movs r0, #0xc8
	lsls r0, r0, #1
_08221E14:
	strh r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r2, sb
	strh r2, [r0]
	movs r0, #0x62
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _08221E5C
	bl Script_GetValue
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _08221E76
	.align 2, 0
_08221E54: .4byte 0x000003E7
_08221E58: .4byte 0x000003EA
_08221E5C:
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r1]
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r0, r7, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r7, r1
	str r2, [r0]
_08221E76:
	str r5, [sp]
	mov r0, r8
	ldr r1, [sp, #0x28]
	adds r2, r6, #0
	mov r3, sl
	bl FUN_08022a70
	mov r0, r8
	adds r1, r4, #0
	adds r2, r4, #0
	mov r3, sb
	bl FUN_08022b2c
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, r8
	movs r4, #0
	strb r5, [r0]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	mov r6, r8
	adds r6, #0xab
	strb r0, [r6]
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r4, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #8
	adds r0, r7, r2
	str r4, [r0]
	adds r1, #8
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #8
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	movs r1, #0xe7
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #8
	adds r0, r7, r2
	str r4, [r0]
	adds r1, #8
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #0xc
	adds r0, r7, r2
	str r4, [r0]
	adds r0, r7, #0
	mov r1, sl
	adds r2, r5, #0
	bl Entity0623_Init_Helper_0821c758
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x38
	str r0, [sp, #4]
	movs r0, #0xc8
	lsls r0, r0, #5
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r4, [sp, #0x18]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #0x30
	bl FUN_08013ba8
	ldr r1, _08221FCC @ =0x00001C1B
	adds r0, r5, #0
	movs r2, #7
	bl FUN_08013c94
	movs r0, #0x61
	bl prepare_08231510
	adds r1, r0, #0
	mov sl, r6
	cmp r1, #0
	beq _08221FEC
	bl Script_GetValue
	ldr r2, _08221FD0 @ =0x000003BE
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221FD4 @ =0x000003C2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221FD8 @ =0x000003C6
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221FDC @ =0x000003CA
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221FE0 @ =0x000003CE
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf4
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221FE4 @ =0x000003D2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08221FE8 @ =0x000003D6
	adds r1, r7, r2
	strh r0, [r1]
	b _0822203A
	.align 2, 0
_08221FCC: .4byte 0x00001C1B
_08221FD0: .4byte 0x000003BE
_08221FD4: .4byte 0x000003C2
_08221FD8: .4byte 0x000003C6
_08221FDC: .4byte 0x000003CA
_08221FE0: .4byte 0x000003CE
_08221FE4: .4byte 0x000003D2
_08221FE8: .4byte 0x000003D6
_08221FEC:
	ldr r2, _08222068 @ =0x000003BE
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
_0822203A:
	adds r0, r7, #0
	mov r1, sb
	bl FUN_0821c950
	adds r0, r7, #0
	bl FUN_0821ca58
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _0822206C
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08022fac
	b _08222076
	.align 2, 0
_08222068: .4byte 0x000003BE
_0822206C:
	mov r0, r8
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_08222076:
	movs r0, #0x41
	bl prepare_08231510
	movs r5, #0x82
	lsls r5, r5, #1
	add r5, r8
	movs r6, #0x86
	lsls r6, r6, #1
	add r6, r8
	cmp r0, #0
	beq _082220AC
	movs r4, #0
	b _082220A0
_08222090:
	bl Script_GetValue
	lsls r2, r4, #2
	mov r1, r8
	adds r1, #0xe8
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
_082220A0:
	cmp r4, #3
	bgt _082220AC
	bl VM_GetPC
	cmp r0, #0
	bne _08222090
_082220AC:
	movs r0, #0x4b
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	ldr r0, _082220CC @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _082220D0
	str r0, [r5]
	adds r0, #0x2c
	b _082220D2
	.align 2, 0
_082220CC: .4byte 0x03002BE0
_082220D0:
	str r0, [r5]
_082220D2:
	str r0, [r6]
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	beq _08222108
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_0821d870
	adds r0, r7, #0
	movs r1, #0xf
	movs r2, #1
	bl FUN_08221268
	ldr r2, _08222104 @ =0x00010010
	mov r1, r8
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08222122
	.align 2, 0
_08222104: .4byte 0x00010010
_08222108:
	movs r0, #0x78
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0821d870
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08221268
_08222122:
	movs r2, #0xfb
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r6, _08222204 @ =0x7FFF7FFF
	movs r4, #0xf
_08222148:
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _08222208 @ =0x05000008
	bl CpuSet
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _08222148
	ldr r0, _0822220C @ =0x03003584
	ldr r0, [r0]
	adds r6, r0, #0
	adds r6, #0xe0
	movs r2, #0xfd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r4, #0xf
_08222176:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _08222210 @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _08222176
	movs r4, #0
	movs r1, #0xf6
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08222214 @ =0x000003D9
	adds r0, r7, r2
	strb r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r4, [r0]
	adds r1, #0x22
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _08222218 @ =0x00000BF6
	adds r0, r7, r2
	strb r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r7, r0
	movs r0, #1
	str r0, [r1]
	ldr r1, _0822221C @ =0x00000808
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08222220 @ =0x00000809
	adds r0, r7, r2
	strb r4, [r0]
	adds r1, #4
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #7
	adds r0, r7, r2
	str r4, [r0]
	bl FUN_0805e67c
	ldr r2, _08222224 @ =0x00000BF8
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0x78
	bl FUN_0805ee80
	ldr r2, _08222228 @ =0x00000BFC
	adds r1, r7, r2
	str r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r7, r1
	str r4, [r0]
	movs r0, #0
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08222204: .4byte 0x7FFF7FFF
_08222208: .4byte 0x05000008
_0822220C: .4byte 0x03003584
_08222210: .4byte 0x04000008
_08222214: .4byte 0x000003D9
_08222218: .4byte 0x00000BF6
_0822221C: .4byte 0x00000808
_08222220: .4byte 0x00000809
_08222224: .4byte 0x00000BF8
_08222228: .4byte 0x00000BFC
