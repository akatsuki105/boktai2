	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08055748
FUN_08055748: @ 0x08055748
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	movs r6, #0
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
	cmp r0, #0
	bge _0805575C
	str r6, [r4, #0x24]
_0805575C:
	ldr r0, [r4, #0x18]
	bl VM_SetPC
	movs r5, #0
	b _0805577C
_08055766:
	bl VM_GetPC
	bl VM_GetValueAtSafe
	adds r7, r0, #0
	bl VM_GetPC
	bl VM_GetValueAt
	adds r6, r0, #0
	adds r5, #1
_0805577C:
	ldr r0, [r4, #0x24]
	cmp r5, r0
	bgt _0805578C
	bl VM_GetPC
	cmp r0, #0
	bne _08055766
	str r5, [r4, #0x24]
_0805578C:
	str r7, [r4, #0x1c]
	str r6, [r4, #0x20]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity8D5C_Update
Entity8D5C_Update: @ 0x08055798
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _080557D4 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _080557E8
	movs r0, #0x40
	ands r1, r0
	movs r4, #1
	cmp r1, #0
	beq _080557B4
	subs r4, #2
_080557B4:
	ldr r0, [r5, #0x2c]
	cmp r0, r4
	bne _080557D8
	ldr r0, [r5, #0x28]
	subs r0, #1
	str r0, [r5, #0x28]
	cmp r0, #0
	bge _080557EA
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08055748
	movs r0, #4
	str r0, [r5, #0x28]
	b _080557EA
	.align 2, 0
_080557D4: .4byte 0x030044E0
_080557D8:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08055748
	movs r0, #0x14
	str r0, [r5, #0x28]
	str r4, [r5, #0x2c]
	b _080557EA
_080557E8:
	str r0, [r5, #0x2c]
_080557EA:
	ldrh r1, [r6, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08055804
_080557F4:
	ldr r4, [r5, #0x24]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08055748
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bne _080557F4
_08055804:
	ldrh r1, [r6, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0805581C
	ldr r0, [r5, #0x20]
	movs r1, #0
	bl VM_ExecByID
	adds r0, r5, #0
	bl KillEntity
_0805581C:
	bl FUN_0823d4c8
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity8D5C_Init
Entity8D5C_Init: @ 0x08055828
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08055874
	bl VM_GetPC
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x24]
	str r0, [r4, #0x2c]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08055748
	ldr r0, _08055864 @ =0x000092B3
	ldr r1, _08055868 @ =0x0000519C
	bl GetFile
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0805586C @ =0x03004430
	ldr r2, _08055870 @ =0x04000008
	bl CpuSet
	movs r0, #0
	b _08055878
	.align 2, 0
_08055864: .4byte 0x000092B3
_08055868: .4byte 0x0000519C
_0805586C: .4byte 0x03004430
_08055870: .4byte 0x04000008
_08055874:
	movs r0, #1
	rsbs r0, r0, #0
_08055878:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity8D5C_Create
Entity8D5C_Create: @ 0x08055880
	push {r4, lr}
	movs r0, #4
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080558B0
	ldr r1, _080558AC @ =Entity8D5C_Update
	movs r2, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity8D5C_Init
	cmp r0, #0
	bge _080558B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080558B2
	.align 2, 0
_080558AC: .4byte Entity8D5C_Update
_080558B0:
	adds r0, r4, #0
_080558B2:
	pop {r4}
	pop {r1}
	bx r1
