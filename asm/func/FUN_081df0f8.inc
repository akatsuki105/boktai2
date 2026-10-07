	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF134
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _081DF14C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF124
	adds r1, r0, #0
	adds r1, #0x56
	movs r0, #1
	strb r0, [r1]
_081DF124:
	ldr r0, _081DF150 @ =0x000002DE
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DF134
	movs r1, #0
	bl VM_ExecByID
_081DF134:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF154
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF22A
	.align 2, 0
_081DF14C: .4byte 0x03002C68
_081DF150: .4byte 0x000002DE
_081DF154:
	movs r7, #0
	movs r4, #0
	ldrh r6, [r5, #0x1a]
	cmp r7, r6
	bge _081DF1A4
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
_081DF164:
	cmp r4, #0
	bge _081DF170
	ldr r1, _081DF16C @ =0x0000FFFF
	b _081DF178
	.align 2, 0
_081DF16C: .4byte 0x0000FFFF
_081DF170:
	ldr r2, [r5, #0x44]
	lsls r1, r4, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF178:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF18E
	movs r1, #1
	b _081DF190
_081DF18E:
	movs r1, #0
_081DF190:
	cmp r1, #0
	beq _081DF19E
	movs r1, #0xff
	ands r1, r3
	cmp r1, #0xa5
	bne _081DF19E
	adds r7, #1
_081DF19E:
	adds r4, #1
	cmp r4, r6
	blt _081DF164
_081DF1A4:
	cmp r7, r6
	bne _081DF1BC
	ldr r2, _081DF1B8 @ =FUN_081df23c
	adds r0, r5, #0
	movs r1, #0x12
	bl Entity9A9F_SetState
	movs r0, #0
	b _081DF22A
	.align 2, 0
_081DF1B8: .4byte FUN_081df23c
_081DF1BC:
	adds r1, r5, #0
	adds r1, #0x25
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	beq _081DF22A
	adds r6, r5, #0
	adds r6, #0x26
	ldrb r1, [r6]
	cmp r1, #0
	bne _081DF222
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DF234 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #5
	bl FUN_0809c08c
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r4, r5, r1
	str r0, [r4]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #9
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r1, #1
	strb r1, [r6]
_081DF222:
	ldr r2, _081DF238 @ =0x000010A5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF22A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF234: .4byte 0x0000FFFF
_081DF238: .4byte 0x000010A5
