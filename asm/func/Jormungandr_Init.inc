	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	str r1, [sp, #4]
	mov r8, r5
	movs r0, #0x74
	movs r1, #5
	bl VM_GetKeywordValue
	str r0, [sp, #8]
	adds r0, r5, #0
	ldr r1, [sp, #8]
	bl FUN_08022a0c
	ldr r0, _080CAD7C @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _080CAD80
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r1, r5, r4
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _080CAD90
	.align 2, 0
_080CAD7C: .4byte 0x03002BE0
_080CAD80:
	movs r6, #0x82
	lsls r6, r6, #1
	adds r0, r5, r6
	str r2, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
_080CAD90:
	ldr r0, _080CADD0 @ =0x000092B3
	ldr r1, _080CADD4 @ =0x00005ABD
	bl GetFile
	ldr r2, _080CADD8 @ =0x00001904
	adds r1, r5, r2
	adds r0, #0x14
	str r0, [r1]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CADE0
	bl Script_GetValue
	str r0, [sp, #0xc]
	bl Script_GetValue
	ldr r4, _080CADDC @ =0x00001916
	adds r1, r5, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r7, r0, #0
	b _080CADF2
	.align 2, 0
_080CADD0: .4byte 0x000092B3
_080CADD4: .4byte 0x00005ABD
_080CADD8: .4byte 0x00001904
_080CADDC: .4byte 0x00001916
_080CADE0:
	ldr r6, _080CAE68 @ =0x00001388
	str r6, [sp, #0xc]
	ldr r0, _080CAE6C @ =0x00001916
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	movs r4, #0x46
	movs r6, #0x32
	movs r7, #0x14
_080CADF2:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080c4520
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080c468c
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080c47a0
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CAE78
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	str r0, [sp, #0x10]
	bl Script_GetValue
	str r0, [sp, #0x14]
	bl Script_GetValue
	str r0, [sp, #0x18]
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	str r0, [sp, #0x1c]
	bl Script_GetValue
	str r0, [sp, #0x20]
	bl Script_GetValue
	ldr r2, _080CAE70 @ =0x00001928
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080CAE74 @ =0x0000192A
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	mov sl, r0
	b _080CAEA6
	.align 2, 0
_080CAE68: .4byte 0x00001388
_080CAE6C: .4byte 0x00001916
_080CAE70: .4byte 0x00001928
_080CAE74: .4byte 0x0000192A
_080CAE78:
	movs r7, #0x64
	movs r6, #0x32
	movs r4, #0x1e
	movs r0, #0x96
	str r0, [sp, #0x10]
	movs r1, #0x96
	str r1, [sp, #0x14]
	movs r2, #0x1e
	str r2, [sp, #0x18]
	movs r0, #0x78
	mov sb, r0
	str r1, [sp, #0x1c]
	str r2, [sp, #0x20]
	ldr r1, _080CAEFC @ =0x00001928
	adds r0, r5, r1
	mov r2, sb
	strh r2, [r0]
	ldr r0, _080CAF00 @ =0x0000192A
	adds r1, r5, r0
	movs r0, #0x5a
	strh r0, [r1]
	movs r1, #0x50
	mov sl, r1
_080CAEA6:
	adds r0, r5, #0
	bl FUN_080c5124
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r4, #0
	bl FUN_080c4840
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r4, #0
	bl FUN_080c48ec
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, r8
	adds r1, #0xab
	movs r6, #0
	strb r0, [r1]
	ldrb r4, [r1]
	cmp r4, #0
	bne _080CAEDC
	b _080CB078
_080CAEDC:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_080c2ba8
	cmp r4, #1
	beq _080CAFA8
	cmp r4, #1
	bgt _080CAF04
	cmp r4, #0
	beq _080CAF0A
	b _080CB0F8
	.align 2, 0
_080CAEFC: .4byte 0x00001928
_080CAF00: .4byte 0x0000192A
_080CAF04:
	cmp r4, #2
	beq _080CAFEC
	b _080CB0F8
_080CAF0A:
	ldr r2, _080CAF78 @ =0x00001934
	adds r0, r5, r2
	ldr r4, _080CAF7C @ =0x080C26CD
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r1, _080CAF80 @ =0x00001BDC
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r2, _080CAF84 @ =0x00001E84
	adds r0, r5, r2
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r1, _080CAF88 @ =0x0000212C
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r2, _080CAF8C @ =0x000008F4
	adds r0, r5, r2
	strb r6, [r0]
	ldr r4, _080CAF90 @ =0x000008F5
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _080CAF94 @ =0x000008F6
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080CAF98 @ =0x000025C5
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _080CAF9C @ =0x000025C6
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _080CAFA0 @ =0x000025C7
	adds r0, r5, r1
	strb r6, [r0]
	subs r4, #0xa
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _080CAFA4 @ =FUN_080c5b6c
	movs r0, #0x2a
	mov r3, r8
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	b _080CB0F4
	.align 2, 0
_080CAF78: .4byte 0x00001934
_080CAF7C: .4byte 0x080C26CD
_080CAF80: .4byte 0x00001BDC
_080CAF84: .4byte 0x00001E84
_080CAF88: .4byte 0x0000212C
_080CAF8C: .4byte 0x000008F4
_080CAF90: .4byte 0x000008F5
_080CAF94: .4byte 0x000008F6
_080CAF98: .4byte 0x000025C5
_080CAF9C: .4byte 0x000025C6
_080CAFA0: .4byte 0x000025C7
_080CAFA4: .4byte FUN_080c5b6c
_080CAFA8:
	ldr r1, _080CAFDC @ =0x000008F4
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080CAFE0 @ =0x000008F5
	adds r0, r5, r2
	strb r6, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080CAFE4 @ =0x000025BC
	adds r0, r5, r2
	strb r4, [r0]
	ldr r1, _080CAFE8 @ =FUN_080c6060
	movs r0, #0x31
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	b _080CB0F8
	.align 2, 0
_080CAFDC: .4byte 0x000008F4
_080CAFE0: .4byte 0x000008F5
_080CAFE4: .4byte 0x000025BC
_080CAFE8: .4byte FUN_080c6060
_080CAFEC:
	adds r0, r5, #0
	bl FUN_080c3f30
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrh r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	subs r2, #0xe8
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	subs r4, #0x10
	adds r0, r5, r4
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	ldr r1, _080CB064 @ =0x000008F4
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r4, _080CB068 @ =0x000008F5
	adds r1, r5, r4
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080CB06C @ =0x000008F6
	adds r0, r5, r1
	strb r3, [r0]
	ldr r4, _080CB070 @ =0x000025BC
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, _080CB074 @ =FUN_080c6354
	movs r0, #0x36
	mov r3, r8
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	movs r0, #2
	bl FUN_0809c08c
	b _080CB0F8
	.align 2, 0
_080CB064: .4byte 0x000008F4
_080CB068: .4byte 0x000008F5
_080CB06C: .4byte 0x000008F6
_080CB070: .4byte 0x000025BC
_080CB074: .4byte FUN_080c6354
_080CB078:
	adds r0, r5, #0
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x18]
	bl FUN_080c59f4
	adds r0, r5, #0
	mov r1, sl
	bl FUN_080c314c
	adds r0, r5, #0
	mov r1, sb
	ldr r2, [sp, #0x1c]
	ldr r3, [sp, #0x20]
	bl FUN_080c3784
	movs r0, #0x64
	movs r1, #0x64
	bl FUN_082464b8
	movs r6, #0xc8
	lsls r6, r6, #5
	adds r1, r5, r6
	str r0, [r1]
	ldr r1, _080CB10C @ =0x000008F4
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r6, _080CB110 @ =0x000008F5
	adds r1, r5, r6
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080CB114 @ =0x000008F6
	adds r0, r5, r1
	strb r4, [r0]
	ldr r6, _080CB118 @ =0x0000260E
	adds r1, r5, r6
	movs r3, #0
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080CB11C @ =0x0000260D
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080CB120 @ =0x00001909
	adds r0, r5, r1
	movs r1, #3
	strb r1, [r0]
	ldr r6, _080CB124 @ =0x0000190B
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080CB128 @ =0x000025BC
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, _080CB12C @ =FUN_080c6c8c
	mov r0, r8
	adds r0, #0xa3
	strb r3, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
_080CB0F4:
	adds r0, #0x1d
	strb r2, [r0]
_080CB0F8:
	movs r0, #0x78
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CB134
	bl Script_GetValue
	ldr r2, _080CB130 @ =0x000025CC
	adds r1, r5, r2
	b _080CB13A
	.align 2, 0
_080CB10C: .4byte 0x000008F4
_080CB110: .4byte 0x000008F5
_080CB114: .4byte 0x000008F6
_080CB118: .4byte 0x0000260E
_080CB11C: .4byte 0x0000260D
_080CB120: .4byte 0x00001909
_080CB124: .4byte 0x0000190B
_080CB128: .4byte 0x000025BC
_080CB12C: .4byte FUN_080c6c8c
_080CB130: .4byte 0x000025CC
_080CB134:
	ldr r4, _080CB150 @ =0x000025CC
	adds r1, r5, r4
	movs r0, #2
_080CB13A:
	strh r0, [r1]
	movs r0, #0x4b
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CB158
	bl Script_GetValue
	ldr r6, _080CB154 @ =0x000025CE
	adds r1, r5, r6
	b _080CB15E
	.align 2, 0
_080CB150: .4byte 0x000025CC
_080CB154: .4byte 0x000025CE
_080CB158:
	ldr r0, _080CB1A8 @ =0x000025CE
	adds r1, r5, r0
	movs r0, #2
_080CB15E:
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r3, r5, r1
	movs r0, #0x40
	str r0, [sp]
	mov r0, r8
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl Boss_Init_08022a70
	mov r0, r8
	ldr r1, [sp, #0xc]
	adds r2, r1, #0
	movs r3, #0xc8
	bl FUN_08022b2c
	ldr r1, _080CB1AC @ =FUN_080c9d00
	mov r0, r8
	adds r0, #0xfc
	str r1, [r0]
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CB1B0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08022fac
	b _080CB1BA
	.align 2, 0
_080CB1A8: .4byte 0x000025CE
_080CB1AC: .4byte FUN_080c9d00
_080CB1B0:
	mov r0, r8
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_080CB1BA:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CB1E0
	movs r4, #0
	mov r6, r8
	adds r6, #0xe8
	b _080CB1D4
_080CB1CC:
	bl Script_GetValue
	stm r6!, {r0}
	adds r4, #1
_080CB1D4:
	cmp r4, #3
	bgt _080CB1E0
	bl VM_GetPC
	cmp r0, #0
	bne _080CB1CC
_080CB1E0:
	ldr r2, _080CB200 @ =0x000025F8
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080c3b80
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CB200: .4byte 0x000025F8
