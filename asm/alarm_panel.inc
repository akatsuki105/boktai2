	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a16b0
FUN_080a16b0: @ 0x080A16B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A16FC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1700 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080A170C
	ldr r0, _080A1704 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r3, #0x28
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0x7f
	bgt _080A170C
	cmp r1, #0x7f
	bgt _080A170C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r1, _080A1708 @ =0x00003FFF
	cmp r0, r1
	bgt _080A170C
	movs r0, #1
	b _080A170E
	.align 2, 0
_080A16FC: .4byte 0x030046A0
_080A1700: .4byte 0x00000942
_080A1704: .4byte 0x03002BE0
_080A1708: .4byte 0x00003FFF
_080A170C:
	movs r0, #0
_080A170E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start AlarmPanel_Update
AlarmPanel_Update: @ 0x080A1714
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080A1740 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1744 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	cmp r5, #0
	bne _080A174C
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A1738
	ldr r0, _080A1748 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A1738:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x46
	b _080A17FC
	.align 2, 0
_080A1740: .4byte 0x030046A0
_080A1744: .4byte 0x00000942
_080A1748: .4byte 0x00000237
_080A174C:
	adds r0, r4, #0
	bl FUN_080a16b0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A17E8
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1778
	ldr r0, _080A17A4 @ =0x00000237
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1778
	movs r1, #0
	bl VM_ExecByID
_080A1778:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x45
	bl Video_SetAuxSpritePltt
	adds r3, r4, #0
	adds r3, #0xac
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrh r0, [r4, #0x1a]
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A17A8
	movs r0, #4
	orrs r2, r0
	b _080A17AE
	.align 2, 0
_080A17A4: .4byte 0x00000237
_080A17A8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r2, r0
_080A17AE:
	str r2, [r3]
	ldrh r1, [r4, #0x1a]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080A17DC
	adds r0, r4, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x84
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #0x80
	str r3, [sp]
	ldr r3, _080A17E4 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
_080A17DC:
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _080A180E
	.align 2, 0
_080A17E4: .4byte 0x0000B546
_080A17E8:
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A17F6
	ldr r0, _080A1818 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A17F6:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x44
_080A17FC:
	bl Video_SetAuxSpritePltt
	adds r2, r4, #0
	adds r2, #0xac
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strh r5, [r4, #0x1a]
_080A180E:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1818: .4byte 0x00000237

	thumb_func_start AlarmPanel_Destroy
AlarmPanel_Destroy: @ 0x080A181C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A182E
	adds r0, r4, #0
	adds r0, #0x20
	bl Mover_Unlink
_080A182E:
	adds r0, r4, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0xac
	bl AuxSprite_Remove
	ldr r0, _080A184C @ =0x00000237
	bl sound_08240740
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A184C: .4byte 0x00000237

	thumb_func_start AlarmPanel_Init
AlarmPanel_Init: @ 0x080A1850
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	strh r1, [r6, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1874
	bl VM_GetValue
	strh r0, [r6, #0x28]
	bl VM_GetValue
	strh r0, [r6, #0x2a]
	bl VM_GetValue
	b _080A1878
_080A1874:
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2a]
_080A1878:
	strh r0, [r6, #0x2c]
	adds r5, r6, #0
	adds r5, #0x64
	adds r4, r6, #0
	adds r4, #0x90
	ldr r1, _080A1900 @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xa
	strh r0, [r5, #0x10]
	movs r0, #3
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x46
	bl Video_SetAuxSpritePltt
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A18BE
	bl VM_GetValue
	cmp r0, #0
	beq _080A18BE
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x64]
_080A18BE:
	movs r0, #0
	strh r0, [r6, #0x1e]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1904
	bl VM_GetValue
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A1906
	adds r4, r6, #0
	adds r4, #0x20
	ldrh r1, [r6, #0x18]
	adds r2, r5, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A1906
	.align 2, 0
_080A1900: .4byte 0x0000A680
_080A1904:
	strh r0, [r6, #0x1c]
_080A1906:
	adds r5, r6, #0
	adds r5, #0xac
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r1, _080A196C @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xb
	strh r0, [r5, #0x10]
	movs r0, #1
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x45
	bl Video_SetAuxSpritePltt
	ldr r0, [r5]
	ldr r1, _080A1970 @ =0x00000201
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	subs r0, #0x80
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x80
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A195E
	bl VM_GetValue
	adds r2, r0, #0
_080A195E:
	adds r1, r6, #0
	adds r1, #0xf4
	str r2, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A196C: .4byte 0x0000A680
_080A1970: .4byte 0x00000201

	thumb_func_start AlarmPanel_Create
AlarmPanel_Create: @ 0x080A1974
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xf8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A19AC
	ldr r1, _080A19A4 @ =AlarmPanel_Update
	ldr r2, _080A19A8 @ =AlarmPanel_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl AlarmPanel_Init
	cmp r0, #0
	bge _080A19AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A19AE
	.align 2, 0
_080A19A4: .4byte AlarmPanel_Update
_080A19A8: .4byte AlarmPanel_Destroy
_080A19AC:
	adds r0, r4, #0
_080A19AE:
	pop {r4, r5}
	pop {r1}
	bx r1
