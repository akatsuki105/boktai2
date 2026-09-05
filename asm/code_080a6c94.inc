	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ a.k.a. InitArray
	thumb_func_start EngineCall_InitArray
EngineCall_InitArray: @ 0x080A6C94
	push {r4, lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	movs r4, #0
	b _080A6CB2
_080A6CA2:
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sp
	adds r1, r4, #0
	bl FUN_0823206c
	adds r4, #1
_080A6CB2:
	bl VM_GetPC
	cmp r0, #0
	bne _080A6CA2
	movs r0, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

@ a.k.a. Loop
	thumb_func_start EngineCall_Loop
EngineCall_Loop: @ 0x080A6CC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r7, sp
	mov r1, sp
	adds r0, r1, #0
	str r0, [r7, #0xc]
	movs r0, #0x61
	bl VM_SeekToKeyword
	bl Script_GetValue
	mov r8, r0
	movs r0, #0x72
	bl VM_SeekToKeyword
	bl Script_GetValue
	mov sb, r0
	mov r1, r8
	lsls r0, r1, #5
	lsrs r0, r0, #3
	mov r1, sp
	subs r1, r1, r0
	mov sp, r1
	mov r0, sp
	str r0, [r7, #8]
	mov r0, r8
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A6D7C @ =0xFFFF0000
	ldr r0, [r7]
	ands r0, r2
	orrs r0, r1
	str r0, [r7]
	mov r1, sp
	str r1, [r7, #4]
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A6D66
	bl Script_GetValue
	mov sl, r0
	movs r0, #0x64
	bl VM_SeekToKeyword
	bl VM_GetPC
	adds r6, r0, #0
	movs r0, #0
	cmp r0, sb
	bge _080A6D66
_080A6D36:
	adds r0, #1
	str r0, [r7, #0x10]
	mov r0, r8
	cmp r0, #0
	ble _080A6D58
	ldr r5, [r7, #8]
	mov r4, r8
_080A6D44:
	adds r0, r6, #0
	bl VM_GetValueAt
	stm r5!, {r0}
	bl VM_GetPC
	adds r6, r0, #0
	subs r4, #1
	cmp r4, #0
	bne _080A6D44
_080A6D58:
	mov r0, sl
	adds r1, r7, #0
	bl Script_ExecByPointer
	ldr r0, [r7, #0x10]
	cmp r0, sb
	blt _080A6D36
_080A6D66:
	movs r0, #0
	ldr r1, [r7, #0xc]
	mov sp, r1
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A6D7C: .4byte 0xFFFF0000

@ a.k.a. rand
	thumb_func_start EngineCall_Rand
EngineCall_Rand: @ 0x080A6D80
	push {lr}
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A6DC0
	bl Script_GetValue
	adds r3, r0, #0
	cmp r3, #0
	ble _080A6DC0
	ldr r2, _080A6DB4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A6DB8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A6DBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r3, #0
	bl Mod
	b _080A6DD4
	.align 2, 0
_080A6DB4: .4byte 0x030046B8
_080A6DB8: .4byte 0x000003FF
_080A6DBC: .4byte 0x0203B400
_080A6DC0:
	ldr r2, _080A6DD8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A6DDC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A6DE0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
_080A6DD4:
	pop {r1}
	bx r1
	.align 2, 0
_080A6DD8: .4byte 0x030046B8
_080A6DDC: .4byte 0x000003FF
_080A6DE0: .4byte 0x0203B400

	thumb_func_start FUN_080a6de4
FUN_080a6de4: @ 0x080A6DE4
	push {lr}
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A6DFC
	ldr r0, _080A6DF8 @ =0x030044E0
	ldrh r0, [r0, #2]
	b _080A6E28
	.align 2, 0
_080A6DF8: .4byte 0x030044E0
_080A6DFC:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A6E10
	ldr r0, _080A6E0C @ =0x030044E0
	ldrh r0, [r0]
	b _080A6E28
	.align 2, 0
_080A6E0C: .4byte 0x030044E0
_080A6E10:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _080A6E24
	ldr r0, _080A6E20 @ =0x030044E0
	ldrh r0, [r0, #2]
	b _080A6E28
	.align 2, 0
_080A6E20: .4byte 0x030044E0
_080A6E24:
	ldr r0, _080A6E2C @ =0x030044E0
	ldrh r0, [r0, #4]
_080A6E28:
	pop {r1}
	bx r1
	.align 2, 0
_080A6E2C: .4byte 0x030044E0

	thumb_func_start FUN_080a6e30
FUN_080a6e30: @ 0x080A6E30
	push {r4, r5, lr}
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A6E5C
	bl VM_GetValueSafe2
	adds r5, r0, #0
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A6E5C
	bl Script_GetValue
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _080A6E62
_080A6E5C:
	movs r0, #1
	rsbs r0, r0, #0
	b _080A6E80
_080A6E62:
	bl Script_GetValue
	cmp r0, #0
	bne _080A6E70
	adds r0, r5, r4
	ldrb r0, [r0]
	b _080A6E80
_080A6E70:
	cmp r0, #1
	beq _080A6E78
	lsls r0, r4, #2
	b _080A6E7A
_080A6E78:
	lsls r0, r4, #1
_080A6E7A:
	adds r0, r5, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
_080A6E80:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a6e88
FUN_080a6e88: @ 0x080A6E88
	push {r4, r5, lr}
	ldr r3, _080A6EB8 @ =0x030047A4
	ldr r1, [r3]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r3]
	cmp r0, #0
	beq _080A6EB0
	ldr r4, _080A6EBC @ =0x030044BC
	ldr r0, [r4]
	movs r5, #8
	ands r0, r5
	cmp r0, #0
	bne _080A6EB0
	bl FUN_08240918
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
_080A6EB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A6EB8: .4byte 0x030047A4
_080A6EBC: .4byte 0x030044BC

	thumb_func_start FUN_080a6ec0
FUN_080a6ec0: @ 0x080A6EC0
	push {lr}
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A6ED2
	bl Script_GetValue
	b _080A6ED4
_080A6ED2:
	movs r0, #0
_080A6ED4:
	bl FUN_080a6e88
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6edc
FUN_080a6edc: @ 0x080A6EDC
	push {r4, lr}
	ldr r2, _080A6F08 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _080A6F0C @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r2]
	ldr r4, _080A6F10 @ =0x030044BC
	ldr r0, [r4]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080A6F02
	bl FUN_08240930
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_080A6F02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A6F08: .4byte 0x030047A4
_080A6F0C: .4byte 0xFFFFFDFF
_080A6F10: .4byte 0x030044BC

	thumb_func_start FUN_080a6f14
FUN_080a6f14: @ 0x080A6F14
	push {lr}
	bl FUN_080a6edc
	pop {r0}
	bx r0
	.align 2, 0

