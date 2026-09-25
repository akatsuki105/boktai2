	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080db7e4
FUN_080db7e4: @ 0x080DB7E4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080db7e8
FUN_080db7e8: @ 0x080DB7E8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x20
	adds r6, r4, r1
	ldrh r1, [r5, #0x16]
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r0, #0
	ble _080DB80C
	subs r0, r1, #1
	strh r0, [r5, #0x16]
	b _080DB968
_080DB80C:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldrh r0, [r5, #8]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r5, #0xa]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	movs r2, #8
	ldrsh r1, [r5, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #8]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0xa]
	movs r2, #0xc
	ldrsh r1, [r5, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0xc]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	ldr r3, [r4, #0x1c]
	lsls r0, r0, #4
	adds r4, r0, r4
	movs r0, #0xa4
	lsls r0, r0, #3
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB8B2
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080DB8BA
_080DB8B2:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB8BA:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB8DE
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080DB8E6
_080DB8DE:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DB8E6:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DB920 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DB958
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB92A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DB924
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DB940
	.align 2, 0
_080DB920: .4byte 0x0000FFFF
_080DB924:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DB93E
_080DB92A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DB93E
	strh r1, [r4, #8]
	movs r2, #1
	b _080DB940
_080DB93E:
	movs r2, #0
_080DB940:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DB95A
_080DB958:
	movs r2, #0
_080DB95A:
	cmp r2, #0
	beq _080DB962
	movs r0, #2
	strb r0, [r5, #0x12]
_080DB962:
	ldrh r0, [r5, #0x14]
	adds r0, #1
	strh r0, [r5, #0x14]
_080DB968:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db970
FUN_080db970: @ 0x080DB970
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x13
	ldrsb r1, [r5, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r4, r0
	bl Particle_Remove
	movs r0, #0
	strb r0, [r5, #0x12]
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x18
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0x13]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db9b4
FUN_080db9b4: @ 0x080DB9B4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r3, #0
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r6, #1
	movs r2, #0
_080DB9C4:
	adds r1, r6, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DB9D4
	movs r0, #1
	b _080DB9D6
_080DB9D4:
	movs r0, #0
_080DB9D6:
	cmp r0, #0
	bne _080DB9F0
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r2, r1
	adds r0, r5, r0
	strb r3, [r0, #0x13]
	adds r2, r6, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _080DB9FA
_080DB9F0:
	adds r2, #0x18
	adds r3, #1
	cmp r3, #0x1f
	ble _080DB9C4
	movs r0, #0
_080DB9FA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dba00
FUN_080dba00: @ 0x080DBA00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #4]
	mov r8, r1
	mov sb, r2
	str r3, [sp, #8]
	cmp r0, #0
	beq _080DBA30
	ldr r0, _080DBA38 @ =0x03000164
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _080DBA3C
	movs r0, #0
	movs r1, #0
	bl Entity080dbe54_Create
	mov sl, r0
	cmp r0, #0
	bne _080DBA3C
_080DBA30:
	movs r0, #1
	rsbs r0, r0, #0
	b _080DBCCE
	.align 2, 0
_080DBA38: .4byte 0x03000164
_080DBA3C:
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, [sp, #8]
	cmp r0, r1
	blt _080DBA48
	b _080DBCCC
_080DBA48:
	ldr r7, _080DBB1C @ =0x030046B8
_080DBA4A:
	mov r0, sl
	bl FUN_080db9b4
	adds r6, r0, #0
	cmp r6, #0
	beq _080DBA30
	movs r1, #0x13
	ldrsb r1, [r6, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	add r0, sl
	str r0, [sp, #0xc]
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6]
	str r1, [r6, #4]
	mov r3, sb
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080DBAA4
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _080DBB20 @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBB24 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r3, [r6]
	adds r0, r0, r3
	strh r0, [r6]
_080DBAA4:
	mov r1, sb
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DBAD8
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBB20 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBB24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	ldrh r3, [r6, #2]
	adds r0, r0, r3
	strh r0, [r6, #2]
_080DBAD8:
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DBB0C
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBB20 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBB24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #4
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	ldrh r3, [r6, #4]
	adds r0, r0, r3
	strh r0, [r6, #4]
_080DBB0C:
	mov r0, r8
	cmp r0, #0
	bne _080DBB28
	strh r0, [r6, #8]
	mov r1, r8
	strh r1, [r6, #0xa]
	strh r1, [r6, #0xc]
	b _080DBBF8
	.align 2, 0
_080DBB1C: .4byte 0x030046B8
_080DBB20: .4byte 0x000003FF
_080DBB24: .4byte 0x0203B400
_080DBB28:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DBB3C
	ldr r0, _080DBB38 @ =0xFFFF0000
	ands r4, r0
	b _080DBB64
	.align 2, 0
_080DBB38: .4byte 0xFFFF0000
_080DBB3C:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBB74 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080DBB78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DBB7C @ =0xFFFF0000
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_080DBB64:
	mov r3, r8
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _080DBB84
	ldr r0, _080DBB80 @ =0x0000FFFF
	ands r4, r0
	b _080DBBAA
	.align 2, 0
_080DBB74: .4byte 0x000003FF
_080DBB78: .4byte 0x0203B400
_080DBB7C: .4byte 0xFFFF0000
_080DBB80: .4byte 0x0000FFFF
_080DBB84:
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _080DBBBC @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBBC0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	bl Mod
	lsls r0, r0, #0x10
	ldr r1, _080DBBC4 @ =0x0000FFFF
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_080DBBAA:
	mov r1, r8
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080DBBCC
	ldr r3, _080DBBC8 @ =0xFFFF0000
	ands r5, r3
	b _080DBBF4
	.align 2, 0
_080DBBBC: .4byte 0x000003FF
_080DBBC0: .4byte 0x0203B400
_080DBBC4: .4byte 0x0000FFFF
_080DBBC8: .4byte 0xFFFF0000
_080DBBCC:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBC40 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080DBC44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DBC48 @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DBBF4:
	str r4, [r6, #8]
	str r5, [r6, #0xc]
_080DBBF8:
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBC40 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBC44 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	strh r0, [r6, #0x16]
	mov r2, sl
	ldr r1, [r2, #0x1c]
	ldr r0, [sp, #0xc]
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	ldr r0, [sp, #0xc]
	adds r1, r2, #0
	bl Particle_SetOffset
	movs r1, #8
	ldr r0, _080DBC4C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080DBC50 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080DBC54
	movs r0, #1
	b _080DBC56
	.align 2, 0
_080DBC40: .4byte 0x000003FF
_080DBC44: .4byte 0x0203B400
_080DBC48: .4byte 0xFFFF0000
_080DBC4C: .4byte 0x030046A0
_080DBC50: .4byte 0x00000934
_080DBC54:
	movs r0, #0
_080DBC56:
	movs r2, #0xd
	cmp r0, #0
	beq _080DBC5E
	movs r2, #0xe
_080DBC5E:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBCE0 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBCE4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #2
	str r2, [sp, #0x14]
	bl Mod
	adds r3, r0, #0
	ldr r0, [sp, #0x3c]
	orrs r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov ip, r3
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	lsls r0, r0, #4
	movs r1, #0xa4
	lsls r1, r1, #3
	adds r0, r0, r1
	add r0, sl
	mov r3, sl
	ldr r1, [r3, #0x18]
	ldr r2, [sp, #0x14]
	mov r3, ip
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, [sp, #0xc]
	ldr r0, [r1]
	ldr r1, _080DBCE8 @ =0x00000201
	orrs r0, r1
	ldr r2, [sp, #0xc]
	str r0, [r2]
	add r3, sp, #0x38
	ldrb r3, [r3]
	strb r3, [r2, #0xf]
	movs r0, #1
	strb r0, [r6, #0x12]
	add r0, sp, #0x40
	ldrh r0, [r0]
	strh r0, [r6, #0x10]
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r2, [sp, #8]
	cmp r1, r2
	bge _080DBCCC
	b _080DBA4A
_080DBCCC:
	movs r0, #0
_080DBCCE:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBCE0: .4byte 0x000003FF
_080DBCE4: .4byte 0x0203B400
_080DBCE8: .4byte 0x00000201

	thumb_func_start FUN_080dbcec
FUN_080dbcec: @ 0x080DBCEC
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #1
	str r4, [sp, #8]
	bl FUN_080dba00
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dbd08
FUN_080dbd08: @ 0x080DBD08
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	bl FUN_080dba00
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity080dbe54_Update
Entity080dbe54_Update: @ 0x080DBD24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DBDA8
	movs r5, #0
	movs r7, #0x80
	lsls r7, r7, #2
	movs r0, #0xe5
	lsls r0, r0, #3
	adds r4, r6, r0
_080DBD40:
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #1
	lsls r1, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080DBD56
	movs r0, #1
	b _080DBD58
_080DBD56:
	movs r0, #0
_080DBD58:
	cmp r0, #0
	beq _080DBDA0
	adds r3, r4, #0
	ldr r0, _080DBDB0 @ =0x030047A4
	ldr r1, _080DBDB4 @ =0x030047A0
	ldr r2, [r0]
	ldr r0, [r1]
	orrs r0, r2
	ands r0, r7
	cmp r0, #0
	bne _080DBD84
	movs r0, #0x80
	lsls r0, r0, #4
	ands r2, r0
	cmp r2, #0
	beq _080DBD8E
	ldr r0, _080DBDB8 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080DBD8E
_080DBD84:
	ldrh r1, [r4, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DBDA0
_080DBD8E:
	ldr r0, _080DBDBC @ =0x085AD320
	ldrb r1, [r3, #0x12]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r2, [r1]
	adds r0, r6, #0
	adds r1, r3, #0
	bl _call_via_r2
_080DBDA0:
	adds r4, #0x18
	adds r5, #1
	cmp r5, #0x1f
	ble _080DBD40
_080DBDA8:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBDB0: .4byte 0x030047A4
_080DBDB4: .4byte 0x030047A0
_080DBDB8: .4byte 0x030044BC
_080DBDBC: .4byte 0x085AD320

	thumb_func_start Entity080dbe54_Destroy
Entity080dbe54_Destroy: @ 0x080DBDC0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r7, r6, r0
	adds r0, #8
	adds r4, r6, r0
_080DBDD0:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DBDE0
	movs r0, #1
	b _080DBDE2
_080DBDE0:
	movs r0, #0
_080DBDE2:
	cmp r0, #0
	beq _080DBDF8
	movs r1, #0x13
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r6, r0
	bl Particle_Remove
_080DBDF8:
	adds r4, #0x18
	adds r5, #1
	cmp r5, #0x1f
	ble _080DBDD0
	movs r1, #0
	ldr r0, _080DBE10 @ =0x03000164
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBE10: .4byte 0x03000164

	thumb_func_start FUN_080dbe14
FUN_080dbe14: @ 0x080DBE14
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DBE30 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x1c]
	ldr r0, _080DBE34 @ =0x0000922E
	ldr r1, _080DBE38 @ =0x0000D1B8
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DBE30: .4byte 0x00001C1A
_080DBE34: .4byte 0x0000922E
_080DBE38: .4byte 0x0000D1B8

	thumb_func_start Entity080dbe54_Init
Entity080dbe54_Init: @ 0x080DBE3C
	push {lr}
	ldr r3, _080DBE50 @ =0x00000724
	adds r2, r0, r3
	str r1, [r2]
	bl FUN_080dbe14
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080DBE50: .4byte 0x00000724

	thumb_func_start Entity080dbe54_Create
Entity080dbe54_Create: @ 0x080DBE54
	push {r4, r5, lr}
	ldr r5, _080DBE8C @ =0x03000164
	ldr r0, [r5]
	cmp r0, #0
	bne _080DBE9E
	ldr r1, _080DBE90 @ =0x00000A28
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _080DBE9C
	ldr r1, _080DBE94 @ =Entity080dbe54_Update
	ldr r2, _080DBE98 @ =Entity080dbe54_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl Entity080dbe54_Init
	cmp r0, #0
	bge _080DBE9C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DBE9E
	.align 2, 0
_080DBE8C: .4byte 0x03000164
_080DBE90: .4byte 0x00000A28
_080DBE94: .4byte Entity080dbe54_Update
_080DBE98: .4byte Entity080dbe54_Destroy
_080DBE9C:
	adds r0, r4, #0
_080DBE9E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dbea4
FUN_080dbea4: @ 0x080DBEA4
	ldr r1, _080DBEAC @ =0x03000164
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DBEAC: .4byte 0x03000164
