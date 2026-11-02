	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	cmp r4, #0
	beq _081EDB14
	ldr r0, _081EDB1C @ =0x030001C8
	ldr r0, [r0]
	cmp r0, #0
	bne _081EDB0A
	bl Entity081edcc4_Create
	cmp r0, #0
	beq _081EDB14
_081EDB0A:
	bl Entity081edcc4_AllocElem
	adds r5, r0, #0
	cmp r5, #0
	bne _081EDB20
_081EDB14:
	movs r0, #1
	rsbs r0, r0, #0
	b _081EDC32
	.align 2, 0
_081EDB1C: .4byte 0x030001C8
_081EDB20:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r5, #0x70]
	str r1, [r5, #0x74]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x78]
	str r1, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r7, #0
	mov r1, r8
	strh r1, [r0]
	adds r4, r5, #0
	adds r4, #0xd2
	mov r0, sb
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xd8
	strh r7, [r0]
	adds r1, r5, #0
	adds r1, #0xd7
	movs r0, #1
	strb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x80
	ldr r2, _081EDBAC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _081EDBB0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldrb r0, [r4]
	cmp r0, #2
	bne _081EDBBC
	str r7, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	ldr r2, _081EDBB4 @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	ldr r0, _081EDBB8 @ =0x00240004
	str r0, [sp]
	ldr r1, [sp, #0x40]
	str r1, [sp, #4]
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	movs r3, #0x40
	bl Hitbox_SetAttack
	b _081EDBE4
	.align 2, 0
_081EDBAC: .4byte 0xFFFF0000
_081EDBB0: .4byte 0x0000FFFF
_081EDBB4: .4byte 0x00002001
_081EDBB8: .4byte 0x00240004
_081EDBBC:
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	ldr r2, _081EDC40 @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	str r7, [sp]
	ldr r1, [sp, #0x40]
	str r1, [sp, #4]
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	movs r3, #0x10
	bl Hitbox_SetAttack
_081EDBE4:
	ldrh r0, [r5]
	strh r0, [r6, #4]
	adds r4, r5, #0
	adds r4, #0x70
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081EDC44 @ =Entity081edcc4Elem_OnHit
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r5, #0
	adds r0, #0xd6
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, _081EDC48 @ =0x00000309
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	adds r2, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r1, r5, #0
	adds r1, #0x44
	adds r0, r5, #0
	bl Mover_SetAuxSprite
	adds r0, r5, #0
	bl FUN_08002a48
	movs r0, #0
_081EDC32:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EDC40: .4byte 0x00002001
_081EDC44: .4byte Entity081edcc4Elem_OnHit
_081EDC48: .4byte 0x00000309
