	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08159ACC
	b _08159C14
_08159ACC:
	movs r1, #0x22
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08159AE0
	movs r0, #1
	b _08159AE2
_08159AE0:
	movs r0, #0
_08159AE2:
	cmp r0, #0
	bne _08159AF6
	ldr r1, _08159B08 @ =0x0000A13F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08159B0C
_08159AF6:
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r5, r0
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	b _08159C14
	.align 2, 0
_08159B08: .4byte 0x0000A13F
_08159B0C:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r5, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _08159B44 @ =gSineTable
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r3, r2, #0
	cmp r0, #0
	blt _08159B48
	asrs r2, r0, #0xc
	b _08159B4E
	.align 2, 0
_08159B44: .4byte gSineTable
_08159B48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08159B4E:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08159B78 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r1, [r4, #5]
	lsls r0, r1, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #7
	adds r3, r1, #0
	cmp r0, #0
	blt _08159B7C
	asrs r2, r0, #0xc
	b _08159B82
	.align 2, 0
_08159B78: .4byte 0xFFFF0000
_08159B7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08159B82:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08159BB0 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r3, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _08159BD8
	cmp r0, #1
	bgt _08159BB4
	cmp r0, #0
	beq _08159BBE
	b _08159BF0
	.align 2, 0
_08159BB0: .4byte 0xFFFF0000
_08159BB4:
	cmp r0, #2
	beq _08159BBE
	cmp r0, #3
	beq _08159BD8
	b _08159BF0
_08159BBE:
	ldr r3, _08159BD4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xa0
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _08159BEC
	.align 2, 0
_08159BD4: .4byte 0xFFFF0000
_08159BD8:
	ldr r3, _08159C1C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xa0
_08159BEC:
	orrs r0, r1
	str r0, [r2, #4]
_08159BF0:
	ldr r1, _08159C20 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
_08159C14:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08159C1C: .4byte 0xFFFF0000
_08159C20: .4byte 0x0000FFFF
