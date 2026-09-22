	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801ad6c
FUN_0801ad6c: @ 0x0801AD6C
	ldr r1, _0801AD74 @ =0x03000094
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801AD74: .4byte 0x03000094

	thumb_func_start FUN_0801ad78
FUN_0801ad78: @ 0x0801AD78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	adds r2, r1, #0
	adds r0, r1, #0
	muls r0, r1, r0
	mov sb, r0
	ldr r3, _0801AE60 @ =0x000002F6
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r3, r0, r1
	cmp r3, #0
	bge _0801ADA6
	movs r3, #0
_0801ADA6:
	adds r7, r0, r1
	cmp r7, #0xb4
	ble _0801ADAE
	movs r7, #0xb4
_0801ADAE:
	subs r0, r2, r0
	mov r0, r8
	lsls r2, r0, #1
	adds r1, r2, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r5, r6, r0
	mov sl, r2
	cmp r3, #0
	ble _0801ADD4
	movs r0, #0
	adds r4, r3, #0
_0801ADCA:
	strh r0, [r5]
	subs r4, #1
	adds r5, #2
	cmp r4, #0
	bne _0801ADCA
_0801ADD4:
	adds r4, r3, #0
	cmp r4, r7
	bge _0801AE28
	movs r3, #0xff
_0801ADDC:
	ldr r1, _0801AE60 @ =0x000002F6
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r0, r4
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sb
	subs r0, r2, r0
	str r3, [sp]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r1, r0
	adds r1, r1, r0
	ldr r3, [sp]
	cmp r2, #0
	bge _0801AE10
	movs r2, #0
_0801AE10:
	cmp r1, #0xf0
	ble _0801AE16
	movs r1, #0xf0
_0801AE16:
	ands r2, r3
	lsls r0, r2, #8
	ands r1, r3
	orrs r0, r1
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, r7
	blt _0801ADDC
_0801AE28:
	adds r4, r7, #0
	cmp r4, #0xb3
	bgt _0801AE3A
	movs r0, #0
_0801AE30:
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, #0xb3
	ble _0801AE30
_0801AE3A:
	mov r1, sl
	add r1, r8
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AE60: .4byte 0x000002F6

	thumb_func_start FUN_0801ae64
FUN_0801ae64: @ 0x0801AE64
	ldr r0, _0801AE7C @ =0x03003518
	movs r1, #0
	str r1, [r0]
	ldr r0, _0801AE80 @ =0x03002CA0
	str r1, [r0]
	ldr r2, _0801AE84 @ =0x03003510
	movs r0, #1
	strh r0, [r2]
	ldr r0, _0801AE88 @ =0x03003514
	strh r1, [r0]
	bx lr
	.align 2, 0
_0801AE7C: .4byte 0x03003518
_0801AE80: .4byte 0x03002CA0
_0801AE84: .4byte 0x03003510
_0801AE88: .4byte 0x03003514

	thumb_func_start Entity12C4_Update
Entity12C4_Update: @ 0x0801AE8C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0801AED8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801AF70
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0xa4
	lsls r1, r1, #0x10
	ldr r0, _0801AEDC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r6, r5, r0
	mov r7, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801AEE0
	asrs r0, r0, #8
	b _0801AEE6
	.align 2, 0
_0801AED8: .4byte 0x03002BE0
_0801AEDC: .4byte 0x0000FFFF
_0801AEE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEE6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801AEF8
	asrs r0, r0, #8
	b _0801AEFE
_0801AEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEFE:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801AF12
	asrs r0, r0, #8
	b _0801AF18
_0801AF12:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AF18:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801AF48 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF4C
	movs r0, #0
	b _0801AF52
	.align 2, 0
_0801AF48: .4byte 0x030047C8
_0801AF4C:
	cmp r0, #0xf0
	ble _0801AF54
	movs r0, #0xf0
_0801AF52:
	strh r0, [r1]
_0801AF54:
	ldr r0, _0801AF64 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF68
	movs r0, #0
	b _0801AF80
	.align 2, 0
_0801AF64: .4byte 0x000002F6
_0801AF68:
	cmp r0, #0xb4
	ble _0801AF82
	movs r0, #0xb4
	b _0801AF80
_0801AF70:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801AFDC @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801AF80:
	strh r0, [r1]
_0801AF82:
	ldrh r1, [r5, #0x22]
	movs r4, #1
	subs r1, r4, r1
	adds r0, r5, #0
	bl FUN_0801ad78
	ldr r2, _0801AFE0 @ =0x03003518
	ldrh r0, [r5, #0x22]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r0, r5, r0
	str r0, [r2]
	ldr r1, _0801AFE4 @ =0x03002CA0
	ldr r0, _0801AFE8 @ =0x04000040
	str r0, [r1]
	ldr r0, _0801AFEC @ =0x03003510
	strh r4, [r0]
	ldr r0, _0801AFF0 @ =0x03003514
	strh r4, [r0]
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801AFF8
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r5, #0x18]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	ldr r1, _0801AFF4 @ =0x0F9F0000
	cmp r0, r1
	ble _0801B01A
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
	b _0801B01A
	.align 2, 0
_0801AFDC: .4byte 0x000002F6
_0801AFE0: .4byte 0x03003518
_0801AFE4: .4byte 0x03002CA0
_0801AFE8: .4byte 0x04000040
_0801AFEC: .4byte 0x03003510
_0801AFF0: .4byte 0x03003514
_0801AFF4: .4byte 0x0F9F0000
_0801AFF8:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	bgt _0801B01A
	strh r1, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
_0801B01A:
	ldrh r0, [r5, #0x22]
	movs r1, #1
	subs r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity12C4_Destroy
Entity12C4_Destroy: @ 0x0801B034
	push {lr}
	sub sp, #4
	bl FUN_0801ae64
	bl VBlankIntrWait
	movs r0, #0xb4
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xf0
	bl Video_SetWindowRect
	ldr r1, _0801B05C @ =0x03000094
	movs r0, #0
	str r0, [r1]
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0
_0801B05C: .4byte 0x03000094

	thumb_func_start Entity12C4_Init
Entity12C4_Init: @ 0x0801B060
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0801B0D8 @ =0x03000094
	str r5, [r0]
	movs r0, #0
	strh r0, [r5, #0x20]
	strh r0, [r5, #0x22]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x1a]
	movs r0, #0x72
	movs r1, #0xfa
	bl VM_GetKeywordValue
	lsls r1, r0, #4
	strh r1, [r5, #0x18]
	lsls r0, r0, #0x14
	ldr r1, _0801B0DC @ =0x0F9F0000
	cmp r0, r1
	ble _0801B092
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
_0801B092:
	movs r0, #0x73
	movs r1, #8
	bl VM_GetKeywordValue
	lsls r0, r0, #4
	strh r0, [r5, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1e]
	ldr r0, _0801B0E0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801B174
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r6, r5, r1
	adds r7, r0, #0
	adds r7, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0E4
	asrs r0, r0, #8
	b _0801B0EA
	.align 2, 0
_0801B0D8: .4byte 0x03000094
_0801B0DC: .4byte 0x0F9F0000
_0801B0E0: .4byte 0x03002BE0
_0801B0E4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B0EA:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0FC
	asrs r0, r0, #8
	b _0801B102
_0801B0FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B102:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801B116
	asrs r0, r0, #8
	b _0801B11C
_0801B116:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B11C:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801B14C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B150
	movs r0, #0
	b _0801B156
	.align 2, 0
_0801B14C: .4byte 0x030047C8
_0801B150:
	cmp r0, #0xf0
	ble _0801B158
	movs r0, #0xf0
_0801B156:
	strh r0, [r1]
_0801B158:
	ldr r0, _0801B168 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B16C
	movs r0, #0
	b _0801B184
	.align 2, 0
_0801B168: .4byte 0x000002F6
_0801B16C:
	cmp r0, #0xb4
	ble _0801B186
	movs r0, #0xb4
	b _0801B184
_0801B174:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801B19C @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801B184:
	strh r0, [r1]
_0801B186:
	movs r4, #0
_0801B188:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801ad78
	adds r4, #1
	cmp r4, #1
	ble _0801B188
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B19C: .4byte 0x000002F6

	thumb_func_start Entity12C4_Create
Entity12C4_Create: @ 0x0801B1A0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x61
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _0801B1C4 @ =0x03000094
	ldr r0, [r0]
	cmp r0, #0
	bne _0801B206
	cmp r1, #0
	beq _0801B1C8
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0xb
	b _0801B1CE
	.align 2, 0
_0801B1C4: .4byte 0x03000094
_0801B1C8:
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #9
_0801B1CE:
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B204
	ldr r1, _0801B1FC @ =Entity12C4_Update
	ldr r2, _0801B200 @ =Entity12C4_Destroy
	adds r0, r4, #0
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Entity12C4_Init
	cmp r0, #0
	bge _0801B204
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B206
	.align 2, 0
_0801B1FC: .4byte Entity12C4_Update
_0801B200: .4byte Entity12C4_Destroy
_0801B204:
	adds r0, r4, #0
_0801B206:
	pop {r4, r5}
	pop {r1}
	bx r1
