	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start EntityBA36_SetRemaining
EntityBA36_SetRemaining: @ 0x080A1010
	push {r4, lr}
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1024
	bl VM_GetValue
	adds r1, r0, #0
	b _080A1028
_080A1024:
	movs r1, #0xe1
	lsls r1, r1, #3
_080A1028:
	ldr r4, _080A1054 @ =0x03002C40
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _080A104E
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A1046
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A1046:
	ldr r0, [r4]
	adds r0, #0x18
	bl FUN_0809c544
_080A104E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1054: .4byte 0x03002C40

	thumb_func_start EntityBA36_GetRemaining
EntityBA36_GetRemaining: @ 0x080A1058
	push {lr}
	ldr r0, _080A1068 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	beq _080A106C
	ldrh r0, [r0, #0x18]
	b _080A106E
	.align 2, 0
_080A1068: .4byte 0x03002C40
_080A106C:
	movs r0, #0
_080A106E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityBA36_Update
EntityBA36_Update: @ 0x080A1074
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	bne _080A109C
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r0, _080A1094 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1098 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	b _080A10D8
	.align 2, 0
_080A1094: .4byte 0x030046A0
_080A1098: .4byte 0x00000934
_080A109C:
	ldr r0, _080A10E0 @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080A10E4 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080A10E8 @ =0xFFFFEFFF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A10D8
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10C8
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10C8:
	bl FUN_0809c58c
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A10D8
	movs r1, #0
	bl VM_ExecByID
_080A10D8:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A10E0: .4byte 0x030046A0
_080A10E4: .4byte 0x00000934
_080A10E8: .4byte 0xFFFFEFFF

	thumb_func_start EntityBA36_Destroy
EntityBA36_Destroy: @ 0x080A10EC
	push {lr}
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10FE
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10FE:
	ldr r1, _080A1108 @ =0x03002C40
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A1108: .4byte 0x03002C40

	thumb_func_start EntityBA36_Init
EntityBA36_Init: @ 0x080A110C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1120
	bl VM_GetValue
	b _080A1124
_080A1120:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A1124:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1134
	bl VM_GetValue
_080A1134:
	str r0, [r4, #0x1c]
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A1156
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A114E
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A114E:
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
_080A1156:
	ldr r0, _080A1164 @ =0x03002C40
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A1164: .4byte 0x03002C40

	thumb_func_start EntityBA36_Create
EntityBA36_Create: @ 0x080A1168
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A11A4 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	bne _080A11B2
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A11B0
	ldr r1, _080A11A8 @ =EntityBA36_Update
	ldr r2, _080A11AC @ =EntityBA36_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityBA36_Init
	cmp r0, #0
	bge _080A11B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A11B2
	.align 2, 0
_080A11A4: .4byte 0x03002C40
_080A11A8: .4byte EntityBA36_Update
_080A11AC: .4byte EntityBA36_Destroy
_080A11B0:
	adds r0, r4, #0
_080A11B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
