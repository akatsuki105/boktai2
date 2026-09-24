	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _081D105C @ =0x0300018C
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _081D0F86
	bl Entity081d16ec_Create
	mov sb, r0
	cmp r0, #0
	bne _081D0F86
	b _081D11A6
_081D0F86:
	mov r0, sb
	bl FUN_081d0eac
	adds r6, r0, #0
	cmp r6, #0
	bne _081D0F94
	b _081D11A6
_081D0F94:
	mov r8, r6
	adds r4, r6, #0
	adds r4, #0x3c
	ldr r1, _081D1060 @ =0x0000BB68
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc6
	strb r2, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D0FD8
	bl Script_GetValue
	strh r0, [r6, #0x1c]
	bl Script_GetValue
	strh r0, [r6, #0x1e]
	bl Script_GetValue
	strh r0, [r6, #0x20]
_081D0FD8:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
	movs r0, #0x52
	movs r1, #2
	bl VM_GetKeywordValue
	strb r0, [r6, #7]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r6, #0
	adds r5, #0xbc
	strb r0, [r5]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xbe
	strh r0, [r1]
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xb2
	strh r0, [r1]
	movs r0, #0x73
	movs r1, #1
	bl VM_GetKeywordValue
	adds r4, r6, #0
	adds r4, #0xb6
	strh r0, [r4]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r6, #0
	adds r7, #0xba
	strh r0, [r7]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	lsls r0, r0, #0x10
	mov sl, r4
	cmp r0, #0
	beq _081D104E
	adds r0, r6, #0
	movs r1, #4
	bl FUN_081d0e74
_081D104E:
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	beq _081D1064
	cmp r0, #1
	beq _081D1074
	b _081D107E
	.align 2, 0
_081D105C: .4byte 0x0300018C
_081D1060: .4byte 0x0000BB68
_081D1064:
	ldr r0, [r6, #0xc]
	ldr r1, _081D1070 @ =0x00000139
	bl Video_SetAuxSpritePltt
	b _081D107E
	.align 2, 0
_081D1070: .4byte 0x00000139
_081D1074:
	ldr r0, [r6, #0xc]
	movs r1, #0x9d
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_081D107E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D10A4
	adds r4, r6, #0
	adds r4, #0x2c
	mov r2, sb
	ldr r1, [r2, #0x18]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	b _081D10BA
_081D10A4:
	adds r4, r6, #0
	adds r4, #0x2c
	mov r0, sb
	ldr r1, [r0, #0x18]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_081D10BA:
	mov r2, sl
	ldrh r1, [r2]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D10F4
	mov r2, r8
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D1100
_081D10F4:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
_081D1100:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D1126
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D1130
_081D1126:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1130:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D1168 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D11A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D116C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1162
	ldrb r0, [r4, #5]
_081D1162:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D117C
	.align 2, 0
_081D1168: .4byte 0x0000FFFF
_081D116C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D117C
	strh r1, [r4, #8]
_081D117C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D11A0
	movs r0, #1
	strb r0, [r4, #7]
_081D11A0:
	adds r0, r6, #0
	bl FUN_081d1924
_081D11A6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
