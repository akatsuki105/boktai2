	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start solar_08241ac0
solar_08241ac0: @ 0x08241AC0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08241B38 @ =0x03002BE0
	ldr r3, [r0]
	adds r6, r0, #0
	cmp r3, #0
	bne _08241AD0
	b _08241CD0
_08241AD0:
	ldr r0, _08241B3C @ =0x030047A4
	ldr r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	beq _08241AE0
	b _08241CD0
_08241AE0:
	movs r2, #0x80
	lsls r2, r2, #2
	ands r2, r1
	cmp r2, #0
	bne _08241AF0
	ldr r0, [r3, #0x1c]
	cmp r0, #2
	bne _08241B64
_08241AF0:
	ldr r7, _08241B40 @ =0x030046A0
	ldr r0, [r7]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r3, r0, r6
	ldr r2, [r3]
	ldr r5, _08241B44 @ =0x0000752F
	cmp r2, r5
	bgt _08241B4C
	movs r1, #0x94
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08241B12
	b _08241CCA
_08241B12:
	ldrh r1, [r4, #0x24]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _08241B1E
	b _08241CCA
_08241B1E:
	ldrh r0, [r4, #0x1e]
	adds r0, r2, r0
	str r0, [r3]
	cmp r0, r5
	bgt _08241B2A
	b _08241CCA
_08241B2A:
	ldr r0, [r7]
	adds r0, r0, r6
	ldr r1, _08241B48 @ =0x00007530
	str r1, [r0]
	bl SetOverheatTime
	b _08241CCA
	.align 2, 0
_08241B38: .4byte 0x03002BE0
_08241B3C: .4byte 0x030047A4
_08241B40: .4byte 0x030046A0
_08241B44: .4byte 0x0000752F
_08241B48: .4byte 0x00007530
_08241B4C:
	ldr r2, _08241B60 @ =0x00000942
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #2
	bgt _08241B5A
	b _08241CCA
_08241B5A:
	bl SetOverheatTime
	b _08241CCA
	.align 2, 0
_08241B60: .4byte 0x00000942
_08241B64:
	ldr r0, _08241B70 @ =0x030044E0
	ldrh r0, [r0]
	cmp r0, #0
	beq _08241B74
	strh r2, [r4, #0x26]
	b _08241B80
	.align 2, 0
_08241B70: .4byte 0x030044E0
_08241B74:
	ldrh r1, [r4, #0x26]
	ldr r0, _08241C04 @ =0x00000383
	cmp r1, r0
	bhi _08241B80
	adds r0, r1, #1
	strh r0, [r4, #0x26]
_08241B80:
	ldr r0, _08241C08 @ =0x030046A0
	ldr r3, [r0]
	movs r7, #0x94
	lsls r7, r7, #4
	adds r1, r3, r7
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r5, r0, #0
	cmp r1, #0
	bgt _08241B96
	b _08241CC4
_08241B96:
	ldrh r1, [r4, #0x24]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _08241BA2
	b _08241CC4
_08241BA2:
	ldrh r1, [r4, #0x26]
	ldr r0, _08241C04 @ =0x00000383
	cmp r1, r0
	bhi _08241C9C
	movs r7, #0xec
	lsls r7, r7, #1
	adds r1, r3, r7
	ldr r2, [r1]
	ldr r0, _08241C0C @ =0x7FFFFFFE
	cmp r2, r0
	bgt _08241BCA
	ldr r7, _08241C10 @ =0x00000942
	adds r0, r3, r7
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r2, r0
	cmp r0, #0
	bge _08241BC8
	ldr r0, _08241C14 @ =0x7FFFFFFF
_08241BC8:
	str r0, [r1]
_08241BCA:
	ldr r2, [r5]
	movs r7, #0xef
	lsls r7, r7, #2
	adds r0, r2, r7
	ldr r1, [r0]
	ldr r0, _08241C18 @ =0x0000270E
	cmp r1, r0
	bgt _08241C52
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08241C1C
	ldr r6, _08241C10 @ =0x00000942
	adds r0, r2, r6
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r0, #5
	lsls r0, r0, #1
	ldrh r7, [r4, #0x28]
	adds r0, r0, r7
	b _08241C2C
	.align 2, 0
_08241C04: .4byte 0x00000383
_08241C08: .4byte 0x030046A0
_08241C0C: .4byte 0x7FFFFFFE
_08241C10: .4byte 0x00000942
_08241C14: .4byte 0x7FFFFFFF
_08241C18: .4byte 0x0000270E
_08241C1C:
	ldr r1, _08241CD8 @ =0x00000942
	adds r0, r2, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r0, #5
	ldrh r2, [r4, #0x28]
	adds r0, r0, r2
_08241C2C:
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x28]
	lsrs r2, r0, #4
	lsls r1, r2, #4
	subs r0, r0, r1
	strh r0, [r4, #0x28]
	ldr r0, [r5]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, [r0]
	adds r1, r1, r2
	str r1, [r0]
	ldr r2, _08241CDC @ =0x0000270F
	cmp r1, r2
	ble _08241C52
	ldr r0, [r5]
	adds r0, r0, r3
	str r2, [r0]
_08241C52:
	ldr r3, [r5]
	movs r6, #0xf0
	lsls r6, r6, #1
	adds r1, r3, r6
	ldr r2, [r1]
	ldr r0, _08241CE0 @ =0x7FFFFFFE
	cmp r2, r0
	bgt _08241C82
	ldr r7, _08241CD8 @ =0x00000942
	adds r0, r3, r7
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r2, r0
	cmp r0, #0
	bge _08241C72
	ldr r0, _08241CE4 @ =0x7FFFFFFF
_08241C72:
	str r0, [r1]
	ldr r1, [r5]
	movs r6, #0xf2
	lsls r6, r6, #1
	adds r1, r1, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08241C82:
	ldrh r1, [r4, #0x24]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0
	bne _08241C9C
	ldr r0, _08241CE8 @ =0x030046A0
	ldr r0, [r0]
	ldr r7, _08241CD8 @ =0x00000942
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl RotItem
_08241C9C:
	ldr r6, _08241CE8 @ =0x030046A0
	ldr r0, [r6]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r2, r0, r5
	ldr r1, [r2]
	ldr r3, _08241CEC @ =0x0000752F
	cmp r1, r3
	bgt _08241CC4
	ldrh r0, [r4, #0x1e]
	adds r0, r1, r0
	str r0, [r2]
	cmp r0, r3
	ble _08241CC4
	ldr r0, [r6]
	adds r0, r0, r5
	ldr r1, _08241CF0 @ =0x00007530
	str r1, [r0]
	bl SetOverheatTime
_08241CC4:
	adds r0, r4, #0
	bl overheat_08241a04
_08241CCA:
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x24]
_08241CD0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08241CD8: .4byte 0x00000942
_08241CDC: .4byte 0x0000270F
_08241CE0: .4byte 0x7FFFFFFE
_08241CE4: .4byte 0x7FFFFFFF
_08241CE8: .4byte 0x030046A0
_08241CEC: .4byte 0x0000752F
_08241CF0: .4byte 0x00007530

	thumb_func_start FUN_08241cf4
FUN_08241cf4: @ 0x08241CF4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0x19]
	cmp r4, #1
	beq _08241D28
	cmp r4, #1
	bgt _08241D08
	cmp r4, #0
	beq _08241D0E
	b _08241D90
_08241D08:
	cmp r4, #2
	beq _08241D40
	b _08241D90
_08241D0E:
	ldrh r0, [r7, #0x20]
	adds r0, #1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08241D90
	bl FUN_08247774
	movs r0, #1
	strb r0, [r7, #0x19]
	strh r4, [r7, #0x20]
	b _08241D90
_08241D28:
	ldrh r0, [r7, #0x20]
	adds r0, #1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08241D90
	movs r0, #2
	strb r0, [r7, #0x19]
	movs r0, #0
	strh r0, [r7, #0x20]
	b _08241D90
_08241D40:
	bl FUN_082418c0
	strh r0, [r7, #0x1c]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	bl FUN_08241774
	strh r0, [r7, #0x1e]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	bl FUN_082417ec
	ldr r5, _08241D98 @ =0x030046A0
	ldr r1, [r5]
	movs r4, #0x94
	lsls r4, r4, #4
	adds r1, r1, r4
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_08241774
	ldr r1, [r5]
	ldr r6, _08241D9C @ =0x00000942
	adds r1, r1, r6
	strh r0, [r1]
	adds r0, r7, #0
	bl solar_08241ac0
	ldr r2, _08241DA0 @ =0x03004870
	ldr r1, [r5]
	adds r4, r1, r4
	ldrh r0, [r4]
	strh r0, [r2]
	ldr r2, _08241DA4 @ =0x03004874
	adds r1, r1, r6
	ldrh r0, [r1]
	strh r0, [r2]
_08241D90:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08241D98: .4byte 0x030046A0
_08241D9C: .4byte 0x00000942
_08241DA0: .4byte 0x03004870
_08241DA4: .4byte 0x03004874

	thumb_func_start FUN_08241da8
FUN_08241da8: @ 0x08241DA8
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _08241DC8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08241DE0
	ldr r0, _08241DCC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _08241DD0
	movs r0, #1
	rsbs r0, r0, #0
	b _08241DD4
	.align 2, 0
_08241DC8: .4byte 0x030047A4
_08241DCC: .4byte 0x03002C68
_08241DD0:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_08241DD4:
	lsls r1, r0, #3
	ldr r0, _08241DDC @ =0x030044E0
	adds r0, r1, r0
	b _08241DE2
	.align 2, 0
_08241DDC: .4byte 0x030044E0
_08241DE0:
	ldr r0, _08241E10 @ =0x030044E0
_08241DE2:
	ldrh r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	ldr r4, _08241E14 @ =0x03004868
	cmp r0, #0
	beq _08241E38
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08241E18
	ldrh r0, [r2, #0x22]
	adds r0, #1
	strh r0, [r2, #0x22]
	ands r0, r3
	cmp r0, #0
	bne _08241E38
	ldrh r0, [r4]
	cmp r0, #0x8b
	bhi _08241E38
	adds r0, #1
	b _08241E36
	.align 2, 0
_08241E10: .4byte 0x030044E0
_08241E14: .4byte 0x03004868
_08241E18:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08241E38
	ldrh r0, [r2, #0x22]
	adds r0, #1
	strh r0, [r2, #0x22]
	ands r0, r3
	cmp r0, #0
	bne _08241E38
	ldrh r0, [r4]
	cmp r0, #0
	beq _08241E38
	subs r0, #1
_08241E36:
	strh r0, [r4]
_08241E38:
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241e40
FUN_08241e40: @ 0x08241E40
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0x19]
	cmp r4, #1
	beq _08241E74
	cmp r4, #1
	bgt _08241E54
	cmp r4, #0
	beq _08241E5A
	b _08241EDE
_08241E54:
	cmp r4, #2
	beq _08241E8C
	b _08241EDE
_08241E5A:
	ldrh r0, [r7, #0x20]
	adds r0, #1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08241EDE
	bl FUN_08247774
	movs r0, #1
	strb r0, [r7, #0x19]
	strh r4, [r7, #0x20]
	b _08241EDE
_08241E74:
	ldrh r0, [r7, #0x20]
	adds r0, #1
	strh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08241EDE
	movs r0, #2
	strb r0, [r7, #0x19]
	movs r0, #0
	strh r0, [r7, #0x20]
	b _08241EDE
_08241E8C:
	adds r0, r7, #0
	bl FUN_08241da8
	strh r0, [r7, #0x1c]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	bl FUN_08241774
	strh r0, [r7, #0x1e]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	bl FUN_082417ec
	ldr r5, _08241EE4 @ =0x030046A0
	ldr r1, [r5]
	movs r4, #0x94
	lsls r4, r4, #4
	adds r1, r1, r4
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_08241774
	ldr r1, [r5]
	ldr r6, _08241EE8 @ =0x00000942
	adds r1, r1, r6
	strh r0, [r1]
	adds r0, r7, #0
	bl solar_08241ac0
	ldr r2, _08241EEC @ =0x03004870
	ldr r1, [r5]
	adds r4, r1, r4
	ldrh r0, [r4]
	strh r0, [r2]
	ldr r2, _08241EF0 @ =0x03004874
	adds r1, r1, r6
	ldrh r0, [r1]
	strh r0, [r2]
_08241EDE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08241EE4: .4byte 0x030046A0
_08241EE8: .4byte 0x00000942
_08241EEC: .4byte 0x03004870
_08241EF0: .4byte 0x03004874

	thumb_func_start FUN_08241ef4
FUN_08241ef4: @ 0x08241EF4
	push {lr}
	adds r2, r0, #0
	ldr r0, _08241F10 @ =0x0300486C
	ldrh r0, [r0]
	cmp r0, #0
	bne _08241F08
	ldr r1, [r2, #0x2c]
	adds r0, r2, #0
	bl _call_via_r1
_08241F08:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08241F10: .4byte 0x0300486C

	thumb_func_start FUN_08241f14
FUN_08241f14: @ 0x08241F14
	push {lr}
	bl FUN_082477b4
	ldr r1, _08241F24 @ =0x03001708
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08241F24: .4byte 0x03001708

	thumb_func_start FUN_08241f28
FUN_08241f28: @ 0x08241F28
	movs r1, #1
	strb r1, [r0, #0x18]
	ldr r1, _08241F58 @ =FUN_08241cf4
	str r1, [r0, #0x2c]
	movs r1, #0
	strb r1, [r0, #0x19]
	strh r1, [r0, #0x20]
	strh r1, [r0, #0x22]
	ldr r2, _08241F5C @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x94
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _08241F60 @ =0x03004870
	ldrh r1, [r1]
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08241F64 @ =0x00000942
	adds r0, r0, r1
	ldr r1, _08241F68 @ =0x03004874
	ldrh r1, [r1]
	strh r1, [r0]
	bx lr
	.align 2, 0
_08241F58: .4byte FUN_08241cf4
_08241F5C: .4byte 0x030046A0
_08241F60: .4byte 0x03004870
_08241F64: .4byte 0x00000942
_08241F68: .4byte 0x03004874

	thumb_func_start ReflectClock
ReflectClock: @ 0x08241F6C
	push {r4, r5, r6, lr}
	bl GetDate
	ldr r4, _08241FC8 @ =0x030046A0
	ldr r1, [r4]
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r1, r2
	str r0, [r1]
	bl GetHour
	ldr r1, [r4]
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r1, r5
	str r0, [r1]
	bl GetMinute
	adds r6, r0, #0
	ldr r2, [r4]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r1, r2, r3
	str r6, [r1]
	ldr r1, _08241FCC @ =0x030047E0
	ldrb r3, [r1, #0xc]
	ldrb r1, [r1, #0xd]
	movs r4, #0
	adds r2, r2, r5
	ldr r2, [r2]
	cmp r2, r3
	blt _08241FB4
	cmp r2, r3
	bne _08241FB6
	cmp r6, r1
	bge _08241FB6
_08241FB4:
	movs r4, #1
_08241FB6:
	ldr r1, _08241FC8 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r1, r1, r2
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08241FC8: .4byte 0x030046A0
_08241FCC: .4byte 0x030047E0

	thumb_func_start clock_08241fd0
clock_08241fd0: @ 0x08241FD0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	bl GetDate
	adds r4, r0, #0
	bl GetHour
	adds r6, r0, #0
	bl GetMinute
	mov sb, r0
	ldr r0, _08242050 @ =0x030047E0
	ldrb r5, [r0, #0xc]
	ldrb r0, [r0, #0xd]
	mov r8, r0
	add r1, sp, #0xc
	add r2, sp, #0x10
	add r0, sp, #8
	adds r3, r4, #0
	bl FUN_0823db08
	add r0, sp, #0x14
	add r1, sp, #0x18
	add r2, sp, #0x1c
	ldr r7, _08242054 @ =0x030046A0
	ldr r3, [r7]
	movs r4, #0xcc
	lsls r4, r4, #1
	adds r3, r3, r4
	ldr r3, [r3]
	bl FUN_0823db08
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	str r4, [sp]
	ldr r4, [sp, #0x1c]
	str r4, [sp, #4]
	bl FUN_0823d9ec
	movs r3, #0
	cmp r0, #1
	bhi _0824209A
	cmp r0, #1
	bne _08242058
	ldr r0, [r7]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0824209A
	cmp r6, r5
	bgt _0824209A
	cmp r6, r5
	bne _08242094
	cmp sb, r8
	blt _08242094
	b _0824209A
	.align 2, 0
_08242050: .4byte 0x030047E0
_08242054: .4byte 0x030046A0
_08242058:
	movs r2, #0
	ldr r1, [r7]
	movs r4, #0xce
	lsls r4, r4, #1
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, r5
	blt _08242078
	cmp r0, r5
	bne _0824207A
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, r8
	bge _0824207A
_08242078:
	movs r2, #1
_0824207A:
	movs r0, #0
	cmp r6, r5
	bgt _08242088
	cmp r6, r5
	bne _0824208A
	cmp sb, r8
	blt _0824208A
_08242088:
	movs r0, #1
_0824208A:
	cmp r2, #0
	beq _08242094
	cmp r0, #0
	beq _08242094
	movs r3, #1
_08242094:
	ldr r5, _08242114 @ =0x030046A0
	cmp r3, #0
	beq _082420D8
_0824209A:
	ldr r1, _08242114 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	strh r2, [r0]
	ldr r0, [r1]
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r2, [r0]
	ldr r0, [r1]
	movs r4, #0xde
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r2, #0
	str r2, [r0]
	ldr r0, [r1]
	adds r3, #6
	adds r0, r0, r3
	str r2, [r0]
	ldr r0, [r1]
	adds r4, #0xf4
	adds r0, r0, r4
	strh r2, [r0]
	ldr r0, [r1]
	adds r3, #0xf2
	adds r0, r0, r3
	strh r2, [r0]
	adds r5, r1, #0
_082420D8:
	ldr r0, [r5]
	movs r4, #0xde
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r0, _08242118 @ =0x0000752F
	cmp r1, r0
	ble _08242100
	bl IsGunCooled
	cmp r0, #0
	beq _08242100
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	str r1, [r0]
	ldr r0, [r5]
	subs r4, #2
	adds r0, r0, r4
	strh r1, [r0]
_08242100:
	bl ReflectClock
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08242114: .4byte 0x030046A0
_08242118: .4byte 0x0000752F

	thumb_func_start FUN_0824211c
FUN_0824211c: @ 0x0824211C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08241f28
	adds r0, r4, #0
	bl clock_08241fd0
	ldr r0, _08242138 @ =0x03001708
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08242138: .4byte 0x03001708

	thumb_func_start FUN_0824213c
FUN_0824213c: @ 0x0824213C
	push {r4, lr}
	ldr r0, _08242170 @ =0x03001708
	ldr r0, [r0]
	cmp r0, #0
	bne _0824217E
	movs r0, #5
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0824217C
	ldr r1, _08242174 @ =FUN_08241ef4
	ldr r2, _08242178 @ =FUN_08241f14
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0824211c
	cmp r0, #0
	bge _0824217C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0824217E
	.align 2, 0
_08242170: .4byte 0x03001708
_08242174: .4byte FUN_08241ef4
_08242178: .4byte FUN_08241f14
_0824217C:
	adds r0, r4, #0
_0824217E:
	pop {r4}
	pop {r1}
	bx r1
