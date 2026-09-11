	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08010d78
FUN_08010d78: @ 0x08010D78
	ldr r1, _08010D80 @ =0x0300004C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08010D80: .4byte 0x0300004C

	thumb_func_start FUN_08010d84
FUN_08010d84: @ 0x08010D84
	push {r4, lr}
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _08010DA8 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0x18
	ldrsh r1, [r3, r4]
	lsls r1, r1, #1
	muls r1, r2, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08010DA8: .4byte 0x03003ED0

	thumb_func_start FUN_08010dac
FUN_08010dac: @ 0x08010DAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08010DE8 @ =gClock
	cmp r0, #0
	bne _08010DC0
	b _08010F56
_08010DC0:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _08010DCE
	cmp r0, #4
	beq _08010DCE
	cmp r0, #5
	bne _08010DEC
_08010DCE:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r1, _08010DE8 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _08010DE8 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _08010E04
	.align 2, 0
_08010DE8: .4byte gClock
_08010DEC:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _08010E5C @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_08010E04:
	movs r4, #0
	ldr r1, _08010E60 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _08010E64 @ =0x03003ED0
	mov sb, r2
_08010E10:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_08010E16:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _08010E16
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E10
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08010E54
	cmp r0, #4
	beq _08010E54
	cmp r0, #5
	bne _08010E68
_08010E54:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _08010E6E
	.align 2, 0
_08010E5C: .4byte gClock
_08010E60: .4byte 0xFFFFD000
_08010E64: .4byte 0x03003ED0
_08010E68:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_08010E6E:
	movs r4, #0
	ldr r2, _08010F68 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_08010E76:
	movs r2, #0
	cmp r2, ip
	bge _08010E92
	adds r3, r6, #0
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_08010E84:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _08010E84
_08010E92:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E76
	mov r0, r8
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r7, r8
	subs r1, r7, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010ED2:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_08010EDA:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010EDA
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _08010ED2
	mov r0, sl
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x16
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010F2A:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_08010F34:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010F34
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _08010F2A
_08010F56:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010F68: .4byte 0x03003ED0
_08010F6C: .4byte 0xFFFFD000

	thumb_func_start FUN_08010f70
FUN_08010f70: @ 0x08010F70
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	add r5, sp, #4
	add r6, sp, #8
	bl GetDate
	adds r3, r0, #0
	mov r0, sp
	adds r1, r5, #0
	adds r2, r6, #0
	bl ParseBCDDate
	movs r5, #0
	movs r0, #0xf
	strh r0, [r4, #0x28]
	adds r0, r4, #0
	bl FUN_08010dac
	strh r5, [r4, #0x28]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Entity95F8_Update
Entity95F8_Update: @ 0x08010FA0
	push {lr}
	bl FUN_08010f70
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity95F8_Destroy
Entity95F8_Destroy: @ 0x08010FAC
	ldr r2, _08010FB4 @ =0x0300004C
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_08010FB4: .4byte 0x0300004C

	thumb_func_start Entity95F8_Init
Entity95F8_Init: @ 0x08010FB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0801100C @ =0x0300004C
	str r6, [r0]
	movs r4, #0
	strh r1, [r6, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #0x1a]
	ldr r0, _08011010 @ =0x0000596F
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x1e]
	ldr r0, _08011014 @ =0x030043F0
	str r0, [r6, #0x20]
	strb r4, [r6, #0x1b]
	ldr r0, _08011018 @ =0x0000C091
	ldrh r1, [r6, #0x1c]
	bl GetFile
	adds r4, r0, #0
	cmp r4, #0
	beq _08011006
	ldr r0, _0801101C @ =0x000092B3
	ldrh r1, [r6, #0x1e]
	bl GetFile
	mov r8, r0
	cmp r0, #0
	bne _08011020
_08011006:
	movs r0, #1
	rsbs r0, r0, #0
	b _080110B6
	.align 2, 0
_0801100C: .4byte 0x0300004C
_08011010: .4byte 0x0000596F
_08011014: .4byte 0x030043F0
_08011018: .4byte 0x0000C091
_0801101C: .4byte 0x000092B3
_08011020:
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08011036
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08011036
	ldrb r0, [r6, #0x1b]
	movs r1, #0
	bl SetBGPrioDirect
	b _08011052
_08011036:
	movs r0, #0
	bl GetTilemapBuffer
	ldrb r2, [r6, #0x1b]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0822bfbc
_08011052:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08010d84
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _080110C4 @ =0x03003ED0
	mov ip, r0
	ldr r1, [r6, #0x20]
	mov sb, r1
_08011076:
	movs r3, #0
	mov r5, ip
	movs r7, #0x18
	ldrsh r0, [r5, r7]
	lsls r0, r0, #1
	adds r1, r4, #1
	cmp r3, r0
	bge _0801109E
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r5, r0, #0
	ldr r4, _080110C4 @ =0x03003ED0
_0801108E:
	strh r5, [r2]
	adds r2, #2
	adds r3, #1
	movs r7, #0x18
	ldrsh r0, [r4, r7]
	lsls r0, r0, #1
	cmp r3, r0
	blt _0801108E
_0801109E:
	adds r4, r1, #0
	cmp r4, #0xe
	ble _08011076
	movs r0, #0xda
	lsls r0, r0, #1
	add r0, r8
	str r0, [r6, #0x24]
	ldr r2, _080110C8 @ =0x04000018
	mov r1, sb
	bl CpuSet
	movs r0, #0
_080110B6:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080110C4: .4byte 0x03003ED0
_080110C8: .4byte 0x04000018

	thumb_func_start Entity95F8_Create
Entity95F8_Create: @ 0x080110CC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08011108
	ldr r1, _08011100 @ =Entity95F8_Update
	ldr r2, _08011104 @ =Entity95F8_Destroy
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Entity95F8_Init
	cmp r0, #0
	bge _08011108
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801110A
	.align 2, 0
_08011100: .4byte Entity95F8_Update
_08011104: .4byte Entity95F8_Destroy
_08011108:
	adds r0, r4, #0
_0801110A:
	pop {r4, r5}
	pop {r1}
	bx r1

