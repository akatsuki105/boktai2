	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08016bf4
FUN_08016bf4: @ 0x08016BF4
	ldr r1, _08016BFC @ =0x03000068
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016BFC: .4byte 0x03000068

	thumb_func_start FUN_08016c00
FUN_08016c00: @ 0x08016C00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0
	mov ip, r0
	movs r6, #0
	movs r1, #1
	mov r8, r1
_08016C12:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r5, r0, r6
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r1, r6, #2
	lsls r0, r1
	mov r1, ip
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	ldrb r0, [r4, #0x1b]
	asrs r0, r6
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08016C82
	lsls r2, r6, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r0, #1
	movs r7, #0
	strh r0, [r3]
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08016C82
	strh r7, [r3]
	adds r0, r4, #0
	adds r0, #0x30
	adds r0, r0, r6
	ldrb r3, [r5]
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _08016C7E
	strb r2, [r5]
	mov r1, r8
	lsls r1, r6
	ldrb r0, [r4, #0x1b]
	bics r0, r1
	strb r0, [r4, #0x1b]
	b _08016C82
_08016C7E:
	adds r0, r3, #1
	strb r0, [r5]
_08016C82:
	adds r6, #1
	cmp r6, #3
	ble _08016C12
	ldrb r1, [r4, #0x19]
	ldrb r2, [r4, #0x1a]
	mov r0, ip
	bl Video_SetMosaic
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _08016C9A
	strb r0, [r4, #0x18]
_08016C9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08016ca4
FUN_08016ca4: @ 0x08016CA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0
	mov ip, r0
	movs r6, #0
	movs r1, #1
	mov r8, r1
_08016CB6:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r5, r0, r6
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r1, r6, #2
	lsls r0, r1
	mov r1, ip
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	ldrb r0, [r4, #0x1b]
	asrs r0, r6
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08016D26
	lsls r2, r6, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r0, #1
	movs r7, #0
	strh r0, [r3]
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08016D26
	strh r7, [r3]
	adds r0, r4, #0
	adds r0, #0x30
	adds r0, r0, r6
	ldrb r3, [r5]
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _08016D22
	strb r2, [r5]
	mov r1, r8
	lsls r1, r6
	ldrb r0, [r4, #0x1b]
	bics r0, r1
	strb r0, [r4, #0x1b]
	b _08016D26
_08016D22:
	subs r0, r3, #1
	strb r0, [r5]
_08016D26:
	adds r6, #1
	cmp r6, #3
	ble _08016CB6
	ldrb r1, [r4, #0x19]
	ldrb r2, [r4, #0x1a]
	mov r0, ip
	bl Video_SetMosaic
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _08016D3E
	strb r0, [r4, #0x18]
_08016D3E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity08016dbc_Update
Entity08016dbc_Update: @ 0x08016D48
	push {lr}
	adds r3, r0, #0
	ldr r2, _08016D64 @ =0x085AA920
	ldrb r1, [r3, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _08016D5E
	bl _call_via_r1
_08016D5E:
	pop {r1}
	bx r1
	.align 2, 0
_08016D64: .4byte 0x085AA920

	thumb_func_start Entity08016dbc_Destroy
Entity08016dbc_Destroy: @ 0x08016D68
	push {lr}
	bl Video_ClearMosaic
	ldr r1, _08016D78 @ =0x03000068
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08016D78: .4byte 0x03000068

	thumb_func_start Entity08016dbc_Init
Entity08016dbc_Init: @ 0x08016D7C
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	ldr r2, _08016DB8 @ =0x03000068
	str r1, [r2]
	movs r2, #0
	strb r2, [r1, #0x18]
	strb r2, [r1, #0x19]
	strb r2, [r1, #0x1a]
	strb r2, [r1, #0x1b]
	movs r4, #0
	movs r6, #0
	movs r5, #0
	adds r3, r1, #0
	adds r3, #0x1c
	adds r2, r1, #0
	adds r2, #0x2c
	adds r1, #0x24
_08016D9E:
	strh r5, [r3]
	strh r5, [r1]
	strb r6, [r2]
	strb r6, [r2, #4]
	adds r3, #2
	adds r2, #1
	adds r1, #2
	adds r4, #1
	cmp r4, #3
	ble _08016D9E
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08016DB8: .4byte 0x03000068

	thumb_func_start Entity08016dbc_Create
Entity08016dbc_Create: @ 0x08016DBC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08016DF8 @ =0x03000068
	ldr r0, [r0]
	cmp r0, #0
	bne _08016E06
	movs r0, #9
	movs r1, #0x34
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016E04
	ldr r1, _08016DFC @ =Entity08016dbc_Update
	ldr r2, _08016E00 @ =Entity08016dbc_Destroy
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Entity08016dbc_Init
	cmp r0, #0
	bge _08016E04
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08016E06
	.align 2, 0
_08016DF8: .4byte 0x03000068
_08016DFC: .4byte Entity08016dbc_Update
_08016E00: .4byte Entity08016dbc_Destroy
_08016E04:
	adds r0, r4, #0
_08016E06:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016e0c
FUN_08016e0c: @ 0x08016E0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov sl, r3
	ldr r0, _08016E3C @ =0x03000068
	ldr r0, [r0]
	cmp r0, #0
	bne _08016E40
	movs r0, #0
	movs r1, #0
	bl Entity08016dbc_Create
	adds r1, r0, #0
	cmp r1, #0
	bne _08016E42
	movs r0, #1
	rsbs r0, r0, #0
	b _08016E9E
	.align 2, 0
_08016E3C: .4byte 0x03000068
_08016E40:
	adds r1, r0, #0
_08016E42:
	strb r4, [r1, #0x18]
	strb r5, [r1, #0x19]
	strb r6, [r1, #0x1a]
	movs r0, #0xf
	strb r0, [r1, #0x1b]
	movs r3, #0
	movs r0, #0x24
	adds r0, r0, r1
	mov r8, r0
	movs r0, #0x2c
	adds r0, r0, r1
	mov ip, r0
	adds r7, r1, #0
	adds r7, #0x30
	movs r6, #0xf
	ldr r5, [sp, #0x24]
	adds r4, r1, #0
	adds r4, #0x1c
	mov sb, r3
_08016E68:
	lsls r1, r3, #1
	mov r0, sb
	strh r0, [r4]
	add r1, r8
	ldrh r0, [r5]
	strh r0, [r1]
	mov r1, ip
	adds r2, r1, r3
	mov r1, sl
	adds r0, r1, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2]
	adds r2, r7, r3
	ldr r1, [sp, #0x20]
	adds r0, r1, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2]
	adds r5, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #3
	ble _08016E68
	movs r0, #0
_08016E9E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016eac
FUN_08016eac: @ 0x08016EAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08016EFA
	movs r4, #0
	add r6, sp, #0xc
	add r7, sp, #0x10
_08016EE6:
	bl Script_GetValue
	mov r1, sp
	adds r1, r1, r4
	adds r1, #8
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08016EE6
	b _08016F0E
_08016EFA:
	add r6, sp, #0xc
	add r7, sp, #0x10
	movs r1, #0
	mov r0, sp
	adds r0, #0xb
_08016F04:
	strb r1, [r0]
	subs r0, #1
	add r2, sp, #8
	cmp r0, r2
	bge _08016F04
_08016F0E:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08016F2A
	movs r4, #0
_08016F1A:
	bl Script_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08016F1A
	b _08016F38
_08016F2A:
	adds r1, r6, #0
	movs r2, #0
	adds r0, r6, #3
_08016F30:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08016F30
_08016F38:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08016F56
	adds r5, r7, #0
	movs r4, #3
_08016F46:
	bl Script_GetValue
	strh r0, [r5]
	adds r5, #2
	subs r4, #1
	cmp r4, #0
	bge _08016F46
	b _08016F64
_08016F56:
	adds r1, r7, #0
	movs r2, #0
	adds r0, r7, #6
_08016F5C:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08016F5C
_08016F64:
	str r6, [sp]
	str r7, [sp, #4]
	mov r0, sl
	mov r1, sb
	mov r2, r8
	add r3, sp, #8
	bl FUN_08016e0c
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016f84
FUN_08016f84: @ 0x08016F84
	push {r4, r5, r6, r7, lr}
	ldr r0, _08016FD4 @ =0x03000068
	ldr r4, [r0]
	cmp r4, #0
	beq _08016FCC
	bl Video_ClearMosaic
	movs r0, #0
	strb r0, [r4, #0x18]
	strb r0, [r4, #0x19]
	strb r0, [r4, #0x1a]
	strb r0, [r4, #0x1b]
	movs r3, #0
	movs r6, #0
	movs r5, #0
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #0x2c
	adds r0, r0, r4
	mov ip, r0
	adds r7, r4, #0
	adds r7, #0x30
	adds r1, r4, #0
	adds r1, #0x24
_08016FB4:
	strh r5, [r2]
	strh r5, [r1]
	mov r4, ip
	adds r0, r4, r3
	strb r6, [r0]
	adds r0, r7, r3
	strb r6, [r0]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08016FB4
_08016FCC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016FD4: .4byte 0x03000068
