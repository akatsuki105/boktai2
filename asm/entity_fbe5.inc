	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start EntityFBE5_Update
EntityFBE5_Update: @ 0x0801A84C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	cmp r1, #7
	bhi _0801A868
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A868:
	cmp r1, #0xf
	bhi _0801A87C
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A87C:
	cmp r1, #0x10
	bne _0801A88A
_0801A880:
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0801A888:
	str r0, [r4, #0x44]
_0801A88A:
	ldr r0, [r4, #0x18]
	cmp r0, #0x1e
	bne _0801A8A4
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	str r2, [sp]
	movs r2, #0x19
	movs r3, #1
	bl MainSprite_SetAnim
_0801A8A4:
	ldr r2, [r4, #0x18]
	cmp r2, #0x59
	bls _0801A8E2
	cmp r2, #0x69
	bhi _0801A8C0
	movs r0, #3
	ands r0, r2
	cmp r0, #1
	bhi _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8C0:
	cmp r2, #0x7e
	bhi _0801A8D6
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8D6:
	cmp r2, #0x7f
	bne _0801A8E2
_0801A8DA:
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
_0801A8E0:
	str r0, [r4, #0x44]
_0801A8E2:
	cmp r2, #0xb4
	bne _0801A900
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x44]
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _0801A912
	movs r1, #0
	bl VM_ExecByID
	b _0801A912
_0801A900:
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	bl MainSprite_AdvanceAnim
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_0801A912:
	movs r0, #0
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityFBE5_Destroy
EntityFBE5_Destroy: @ 0x0801A91C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0801A93C @ =Particle_DrawList
	ldr r2, _0801A940 @ =AuxSprite_DrawList
	ldr r3, _0801A944 @ =MainSprite_DrawList
	movs r0, #0
	bl Video_SetDrawPasses
	adds r4, #0x3c
	adds r0, r4, #0
	bl MainSprite_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801A93C: .4byte Particle_DrawList
_0801A940: .4byte AuxSprite_DrawList
_0801A944: .4byte MainSprite_DrawList

	thumb_func_start EntityFBE5_Init
EntityFBE5_Init: @ 0x0801A948
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r6, r0, #0
	ldr r0, _0801A968 @ =0x0000CB05
	ldr r1, _0801A96C @ =0x0000D3DA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0801A970
	movs r0, #1
	rsbs r0, r0, #0
	b _0801AA84
	.align 2, 0
_0801A968: .4byte 0x0000CB05
_0801A96C: .4byte 0x0000D3DA
_0801A970:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r7, r4, #0
	cmp r0, #0
	beq _0801A9CC
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0801A9C4 @ =0xFFFF0000
	ldr r1, [sp, #0x24]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x24]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0801A9C8 @ =0x0000FFFF
	ldr r1, [sp, #0x24]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r4
	b _0801A9E8
	.align 2, 0
_0801A9C4: .4byte 0xFFFF0000
_0801A9C8: .4byte 0x0000FFFF
_0801A9CC:
	ldr r2, _0801AA90 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	movs r1, #0x78
	orrs r0, r1
	ldr r1, _0801AA94 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
_0801A9E8:
	str r0, [r1, #4]
	mov r8, r1
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x9c
	str r0, [r1]
	movs r4, #0
	str r4, [r6, #0x18]
	adds r5, r6, #0
	adds r5, #0x3c
	ldr r3, _0801AA98 @ =0x00002011
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x18
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _0801AA9C @ =FUN_0822e424
	ldr r2, _0801AAA0 @ =FUN_0822af38
	ldr r3, _0801AAA4 @ =FUN_0822f264
	movs r0, #0
	bl Video_SetDrawPasses
	movs r0, #2
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0x1f
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	movs r0, #3
	movs r1, #5
	add r2, sp, #0x10
	bl Entity6978_SetRequest
	movs r2, #0
	adds r4, r6, #0
	adds r4, #0xa0
	movs r1, #0x76
	adds r1, r1, r6
	mov ip, r1
	adds r5, #0x48
	adds r6, r4, #0
	ldr r1, _0801AAA8 @ =0x00001084
_0801AA60:
	lsls r0, r2, #5
	adds r3, r2, #1
	movs r2, #0xf
	adds r0, r0, r6
	adds r0, #0x1e
_0801AA6A:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _0801AA6A
	adds r2, r3, #0
	cmp r2, #0xf
	ble _0801AA60
	ldr r0, _0801AAAC @ =0x00006541
	mov r3, ip
	strh r0, [r3]
	str r4, [r5]
	movs r0, #0
_0801AA84:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801AA90: .4byte 0xFFFF0000
_0801AA94: .4byte 0x0000FFFF
_0801AA98: .4byte 0x00002011
_0801AA9C: .4byte FUN_0822e424
_0801AAA0: .4byte FUN_0822af38
_0801AAA4: .4byte FUN_0822f264
_0801AAA8: .4byte 0x00001084
_0801AAAC: .4byte 0x00006541

	thumb_func_start EntityFBE5_Create
EntityFBE5_Create: @ 0x0801AAB0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa8
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AAEC
	ldr r1, _0801AAE4 @ =EntityFBE5_Update
	ldr r2, _0801AAE8 @ =EntityFBE5_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityFBE5_Init
	cmp r0, #0
	bge _0801AAEC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AAEE
	.align 2, 0
_0801AAE4: .4byte EntityFBE5_Update
_0801AAE8: .4byte EntityFBE5_Destroy
_0801AAEC:
	adds r0, r4, #0
_0801AAEE:
	pop {r4, r5}
	pop {r1}
	bx r1
