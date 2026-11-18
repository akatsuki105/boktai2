	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	mov sl, r6
	ldr r2, _081BBEDC @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BBEE0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BBEE2
	.align 2, 0
_081BBEDC: .4byte 0x0000046D
_081BBEE0:
	movs r0, #0
_081BBEE2:
	cmp r0, #0
	bne _081BBEE8
	b _081BBFEC
_081BBEE8:
	ldrb r5, [r6, #5]
	ldr r0, _081BBF44 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	strb r0, [r6, #5]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	strb r5, [r6, #5]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BBF48 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BBF4C @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BBF58
	ldr r2, _081BBF50 @ =0x000004B7
	adds r0, r6, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r2, _081BBF54 @ =0x0000046E
	adds r7, r6, r2
	b _081BBFDA
	.align 2, 0
_081BBF44: .4byte 0x000006C5
_081BBF48: .4byte 0x085ADFA8
_081BBF4C: .4byte 0x0000025D
_081BBF50: .4byte 0x000004B7
_081BBF54: .4byte 0x0000046E
_081BBF58:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _081BBFC8 @ =0x000004B7
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BBFCC @ =0x0000046E
	adds r7, r6, r0
	cmp r1, ip
	bne _081BBF94
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BBF94
	cmp r4, #1
	bne _081BBF86
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BBFDE
_081BBF86:
	cmp r4, #0
	bne _081BBF94
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BBFDE
_081BBF94:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov sb, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BBFA8
	movs r3, #6
_081BBFA8:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BBFD0
	ldr r0, [r5, #8]
	mov r3, sb
	orrs r0, r3
	b _081BBFD8
	.align 2, 0
_081BBFC8: .4byte 0x000004B7
_081BBFCC: .4byte 0x0000046E
_081BBFD0:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BBFD8:
	str r0, [r5, #8]
_081BBFDA:
	movs r0, #0
	strb r0, [r7]
_081BBFDE:
	ldr r1, _081BC034 @ =0x0000046E
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _081BC038 @ =0x000006C3
	add r0, r8
	strb r1, [r0]
_081BBFEC:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081BC03C @ =gSineTable
	ldr r0, _081BC040 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _081BC044 @ =0x000006B6
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081BC048
	asrs r0, r0, #0x10
	b _081BC04E
	.align 2, 0
_081BC034: .4byte 0x0000046E
_081BC038: .4byte 0x000006C3
_081BC03C: .4byte gSineTable
_081BC040: .4byte 0x000006C5
_081BC044: .4byte 0x000006B6
_081BC048:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_081BC04E:
	adds r3, r0, #0
	ldr r0, _081BC070 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _081BC074 @ =0x000006B6
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _081BC078
	asrs r0, r0, #0x10
	b _081BC07E
	.align 2, 0
_081BC070: .4byte 0x000006C5
_081BC074: .4byte 0x000006B6
_081BC078:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_081BC07E:
	adds r2, r3, #0
	cmp r3, #0
	bge _081BC086
	rsbs r2, r3, #0
_081BC086:
	adds r1, r0, #0
	cmp r0, #0
	bge _081BC08E
	rsbs r1, r0, #0
_081BC08E:
	cmp r2, r1
	bge _081BC098
	mov r3, sl
	strh r0, [r3, #0x14]
	b _081BC09C
_081BC098:
	mov r0, sl
	strh r3, [r0, #0x10]
_081BC09C:
	ldr r2, _081BC0CC @ =0x000006B6
	add r2, r8
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bgt _081BC0D8
	movs r3, #0
	strh r3, [r2]
	ldr r1, _081BC0D0 @ =0x000006C3
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _081BC0DE
	ldr r0, _081BC0D4 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	strh r3, [r2]
	b _081BC0DE
	.align 2, 0
_081BC0CC: .4byte 0x000006B6
_081BC0D0: .4byte 0x000006C3
_081BC0D4: .4byte 0x0000046B
_081BC0D8:
	adds r0, r1, #0
	subs r0, #0x10
	strh r0, [r2]
_081BC0DE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
