	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081e19e0
FUN_081e19e0: @ 0x081E19E0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19e4
FUN_081e19e4: @ 0x081E19E4
	push {lr}
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	pop {r0}
	bx r0

	thumb_func_start FUN_081e19f0
FUN_081e19f0: @ 0x081E19F0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19f4
FUN_081e19f4: @ 0x081E19F4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19f8
FUN_081e19f8: @ 0x081E19F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19fc
FUN_081e19fc: @ 0x081E19FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	bl TextBox_Start
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextBox_SetRect
	movs r0, #0
	bl TextBox_ShowLine
	ldr r0, _081E1A3C @ =0x000026BB
	bl TextBox_SetBgPltt
	movs r0, #1
	bl TextBox_SetInstant
	adds r1, r4, #0
	adds r1, #0x61
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081E1A40 @ =0xFFFFFBFF
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1A3C: .4byte 0x000026BB
_081E1A40: .4byte 0xFFFFFBFF

	thumb_func_start FUN_081e1a44
FUN_081e1a44: @ 0x081E1A44
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081E1A88 @ =0x0000C091
	ldr r1, _081E1A8C @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x58]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1A88: .4byte 0x0000C091
_081E1A8C: .4byte 0x0000A413

	thumb_func_start FUN_081e1a90
FUN_081e1a90: @ 0x081E1A90
	push {r4, r5, lr}
	adds r4, r0, #0
	bl TextBox_Close
	movs r0, #0
	bl ClearBGTilemapBuffer
	bl Sio_Reset
	bl Sio_Start
	adds r3, r0, #0
	ldr r2, _081E1AF0 @ =FUN_081e1cec
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r2, r4, #0
	adds r2, #0x69
	movs r0, #1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x6a
	movs r0, #0
	strb r0, [r1]
	adds r5, r1, #0
	cmp r3, #0
	bge _081E1AF8
	subs r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E1AF4 @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r3, [r4, #0x4c]
	movs r0, #1
	strb r0, [r2]
	movs r0, #5
	strb r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1B3A
	.align 2, 0
_081E1AF0: .4byte FUN_081e1cec
_081E1AF4: .4byte FUN_081e1f80
_081E1AF8:
	cmp r3, #0
	bne _081E1B0A
	movs r0, #0x20
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl FUN_08238114
	b _081E1B16
_081E1B0A:
	movs r0, #0x40
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl FUN_08238120
_081E1B16:
	str r0, [r4, #0x70]
	bl FUN_08238480
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6d
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x6c
	movs r1, #0
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
_081E1B3A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1b40
FUN_081e1b40: @ 0x081E1B40
	push {r4, lr}
	adds r4, r0, #0
	cmp r2, #0
	beq _081E1B58
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E1B60
_081E1B58:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #4
	strb r0, [r1]
_081E1B60:
	ldr r2, _081E1B8C @ =FUN_081e1ff8
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1B8C: .4byte FUN_081e1ff8

	thumb_func_start FUN_081e1b90
FUN_081e1b90: @ 0x081E1B90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1BA8
	movs r0, #1
	b _081E1BAA
_081E1BA8:
	movs r0, #0
_081E1BAA:
	adds r7, r0, #0
	cmp r7, #0
	bne _081E1C80
	movs r0, #0
	mov r8, r0
	bl FUN_0823812c
	adds r5, r0, #0
	cmp r5, #0
	beq _081E1BC8
	cmp r5, #1
	beq _081E1BE4
	adds r1, r6, #0
	adds r1, #0x6b
	b _081E1C0E
_081E1BC8:
	bl FUN_082380f4
	mov r8, r0
	bl FUN_08238114
	ldr r1, [r6, #0x70]
	cmp r1, r0
	beq _081E1BF4
	adds r4, r6, #0
	adds r4, #0x6b
	strb r5, [r4]
	bl FUN_08238114
	b _081E1C0A
_081E1BE4:
	bl FUN_082380d4
	mov r8, r0
	bl FUN_08238120
	ldr r1, [r6, #0x70]
	cmp r1, r0
	bne _081E1C00
_081E1BF4:
	adds r1, r6, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _081E1C0E
_081E1C00:
	adds r4, r6, #0
	adds r4, #0x6b
	strb r7, [r4]
	bl FUN_08238120
_081E1C0A:
	str r0, [r6, #0x70]
	adds r1, r4, #0
_081E1C0E:
	ldrb r0, [r1]
	cmp r0, #0xa
	bhi _081E1C2C
	mov r0, r8
	cmp r0, #0
	bne _081E1C30
	adds r1, r6, #0
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _081E1C38
_081E1C2C:
	movs r0, #1
	b _081E1C82
_081E1C30:
	adds r1, r6, #0
	adds r1, #0x6c
	movs r0, #0
	strb r0, [r1]
_081E1C38:
	bl FUN_08238094
	cmp r0, #0
	blt _081E1C2C
	bl FUN_0823812c
	cmp r0, #0
	blt _081E1C80
	bl FUN_0823812c
	adds r1, r6, #0
	adds r1, #0x6d
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r4, r1, #0
	cmp r0, r2
	beq _081E1C80
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1C6A
	movs r0, #1
	b _081E1C6C
_081E1C6A:
	movs r0, #0
_081E1C6C:
	cmp r0, #0
	bne _081E1C2C
	bl FUN_0823812c
	strb r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	orrs r0, r1
	str r0, [r6, #0x64]
_081E1C80:
	movs r0, #0
_081E1C82:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1c8c
FUN_081e1c8c: @ 0x081E1C8C
	push {lr}
	adds r2, r0, #0
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _081E1CAE
	adds r0, r2, #0
	bl FUN_08238538
	cmp r0, #0
	ble _081E1CA6
	movs r0, #1
	b _081E1CB2
_081E1CA6:
	cmp r0, #0
	blt _081E1CAE
	movs r0, #0
	b _081E1CB2
_081E1CAE:
	movs r0, #1
	rsbs r0, r0, #0
_081E1CB2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e1cb8
FUN_081e1cb8: @ 0x081E1CB8
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, [r4]
	cmp r0, #0
	blt _081E1CD0
	bl FUN_082384f4
	cmp r0, #0
	bne _081E1CDE
	movs r0, #1
	b _081E1CE4
_081E1CD0:
	adds r0, r2, #0
	movs r1, #0x10
	bl FUN_082384b0
	str r0, [r4]
	cmp r0, #0
	blt _081E1CE2
_081E1CDE:
	movs r0, #2
	b _081E1CE4
_081E1CE2:
	movs r0, #0
_081E1CE4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e1cec
FUN_081e1cec: @ 0x081E1CEC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1CFE
	movs r0, #0
	strb r0, [r1]
_081E1CFE:
	adds r0, r2, #0
	bl FUN_081e1d7c
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1d08
FUN_081e1d08: @ 0x081E1D08
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1D1A
	movs r0, #0
	strb r0, [r1]
_081E1D1A:
	movs r1, #1
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1D28
	movs r0, #1
	b _081E1D2A
_081E1D28:
	movs r0, #0
_081E1D2A:
	cmp r0, #0
	beq _081E1D72
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x50
	bl FUN_081e1cb8
	cmp r0, #1
	bne _081E1D72
	ldr r1, [r4, #0x78]
	cmp r1, #0
	beq _081E1D4A
	ldr r0, [r4, #0x74]
	bl _call_via_r1
_081E1D4A:
	movs r0, #0
	strh r0, [r4, #0x3c]
	subs r0, #2
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x50]
	ldr r2, _081E1D78 @ =FUN_081e1cec
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1D72:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1D78: .4byte FUN_081e1cec

	thumb_func_start FUN_081e1d7c
FUN_081e1d7c: @ 0x081E1D7C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	ldr r1, [r4, #0x64]
	bl FUN_081e1c8c
	cmp r0, #0
	beq _081E1D96
	cmp r0, #0
	ble _081E1E24
	cmp r0, #1
	beq _081E1D9E
	b _081E1E24
_081E1D96:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x50]
	b _081E1E24
_081E1D9E:
	ldrh r0, [r4, #0x3c]
	adds r1, r0, #0
	cmp r1, #6
	bne _081E1DAA
	movs r0, #1
	b _081E1DAC
_081E1DAA:
	movs r0, #0
_081E1DAC:
	cmp r0, #0
	beq _081E1DB4
	movs r0, #0x82
	b _081E1DF8
_081E1DB4:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bne _081E1DC0
	movs r0, #1
	b _081E1DC2
_081E1DC0:
	movs r0, #0
_081E1DC2:
	cmp r0, #0
	beq _081E1DCC
	movs r0, #0x81
	lsls r0, r0, #1
	b _081E1DF8
_081E1DCC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _081E1DD8
	movs r0, #1
	b _081E1DDA
_081E1DD8:
	movs r0, #0
_081E1DDA:
	cmp r0, #0
	beq _081E1DE8
	ldr r0, _081E1DE4 @ =0x00000202
	b _081E1DF8
	.align 2, 0
_081E1DE4: .4byte 0x00000202
_081E1DE8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _081E1DF4
	movs r0, #1
	b _081E1DF6
_081E1DF4:
	movs r0, #0
_081E1DF6:
	movs r0, #2
_081E1DF8:
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	ldr r2, _081E1E20 @ =FUN_081e1e2c
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	subs r0, #5
	str r0, [r4, #0x50]
	movs r0, #1
	b _081E1E26
	.align 2, 0
_081E1E20: .4byte FUN_081e1e2c
_081E1E24:
	movs r0, #0
_081E1E26:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1e2c
FUN_081e1e2c: @ 0x081E1E2C
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1E3E
	movs r0, #0
	strb r0, [r1]
_081E1E3E:
	movs r1, #2
	ldr r0, [r4, #0x64]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _081E1E5A
	movs r0, #1
	b _081E1E5C
_081E1E5A:
	movs r0, #0
_081E1E5C:
	cmp r0, #0
	beq _081E1EA0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #1
	strh r0, [r4, #0x3c]
	ldr r0, _081E1E98 @ =0x030046A0
	ldr r2, [r0]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x40]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x44]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x48]
_081E1E8C:
	ldr r2, _081E1E9C @ =FUN_081e1d08
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	b _081E1F10
	.align 2, 0
_081E1E98: .4byte 0x030046A0
_081E1E9C: .4byte FUN_081e1d08
_081E1EA0:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1EB2
	movs r0, #1
	b _081E1EB4
_081E1EB2:
	movs r0, #0
_081E1EB4:
	cmp r0, #0
	beq _081E1EDC
	ldr r1, _081E1ED4 @ =0xFFFFFEFF
	ands r1, r2
	str r1, [r4, #0x64]
	movs r0, #0
	strh r0, [r4, #0x3c]
	ldr r0, _081E1ED8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [r4, #0x40]
	b _081E1E8C
	.align 2, 0
_081E1ED4: .4byte 0xFFFFFEFF
_081E1ED8: .4byte 0x030046A0
_081E1EDC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E1EEA
	movs r0, #1
	b _081E1EEC
_081E1EEA:
	movs r0, #0
_081E1EEC:
	cmp r0, #0
	beq _081E1F34
	ldr r0, _081E1F2C @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r4, #0x64]
	movs r0, #2
	strh r0, [r4, #0x3c]
	bl FUN_08243104
	str r0, [r4, #0x40]
	bl FUN_08243140
	str r0, [r4, #0x44]
	ldr r2, _081E1F30 @ =FUN_081e1d08
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
_081E1F10:
	str r2, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1F74
	.align 2, 0
_081E1F2C: .4byte 0xFFFFFDFF
_081E1F30: .4byte FUN_081e1d08
_081E1F34:
	ldr r2, [r4, #0x7c]
	cmp r2, #0
	beq _081E1F44
	ldr r0, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x3c
	bl _call_via_r2
_081E1F44:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1F56
	movs r0, #1
	b _081E1F58
_081E1F56:
	movs r0, #0
_081E1F58:
	cmp r0, #0
	bne _081E1F74
	ldr r1, _081E1F7C @ =FUN_081e1cec
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	str r1, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1F74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1F7C: .4byte FUN_081e1cec

	thumb_func_start FUN_081e1f80
FUN_081e1f80: @ 0x081E1F80
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E1FD6
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl TextBox_ShowLine
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E1FD6:
	adds r1, r5, #0
	adds r1, #0x62
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E1FE6
	adds r0, #1
	strh r0, [r1]
	b _081E1FF0
_081E1FE6:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r5, #0x64]
	orrs r0, r1
	str r0, [r5, #0x64]
_081E1FF0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1ff8
FUN_081e1ff8: @ 0x081E1FF8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E204E
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl TextBox_ShowLine
	movs r0, #1
	bl TextBox_SetInstant
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E204E:
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0x9c
	bne _081E2072
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E20D0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081E2072:
	ldrh r0, [r4]
	cmp r0, #0xb4
	bls _081E20C0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	adds r0, #0x80
	ldr r1, [r0]
	cmp r1, #0
	beq _081E20A0
	adds r0, r5, #0
	bl _call_via_r1
_081E20A0:
	bl Taiyo_Enable
	ldr r0, _081E20D4 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E20BA
	movs r1, #0
	bl VM_ExecByID
_081E20BA:
	adds r0, r5, #0
	bl KillEntity
_081E20C0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E20D0: .4byte 0x0000FFFF
_081E20D4: .4byte 0x0300481C

	thumb_func_start FUN_081e20d8
FUN_081e20d8: @ 0x081E20D8
	push {lr}
	adds r1, r0, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E20E8
	movs r0, #0
	strb r0, [r1]
_081E20E8:
	pop {r0}
	bx r0

	thumb_func_start FUN_081e20ec
FUN_081e20ec: @ 0x081E20EC
	push {r4, lr}
	adds r4, r0, #0
	bl Taiyo_Disable
	ldr r1, _081E210C @ =0x0300481C
	movs r0, #1
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2110
	movs r0, #1
	b _081E2112
	.align 2, 0
_081E210C: .4byte 0x0300481C
_081E2110:
	movs r0, #0
_081E2112:
	cmp r0, #0
	bne _081E211C
	ldr r1, _081E2130 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081E211C:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E2134
	movs r0, #1
	b _081E2136
	.align 2, 0
_081E2130: .4byte 0x030047B8
_081E2134:
	movs r0, #0
_081E2136:
	cmp r0, #0
	beq _081E2148
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21A6
	adds r0, r4, #0
	bl _call_via_r1
	b _081E21A6
_081E2148:
	ldr r1, _081E215C @ =0x030047B8
	movs r0, #1
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081E2160
	movs r0, #1
	b _081E2162
	.align 2, 0
_081E215C: .4byte 0x030047B8
_081E2160:
	movs r0, #0
_081E2162:
	cmp r0, #0
	beq _081E21B0
	bl FUN_0823849c
	adds r0, r4, #0
	bl FUN_081e1b90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E21B0
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r2, _081E21AC @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	bl Sio_Stop
_081E21A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E21BE
	.align 2, 0
_081E21AC: .4byte FUN_081e1f80
_081E21B0:
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21BC
	adds r0, r4, #0
	bl _call_via_r1
_081E21BC:
	movs r0, #1
_081E21BE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e21c4
FUN_081e21c4: @ 0x081E21C4
	push {lr}
	bl Sio_Stop
	ldr r1, _081E21D8 @ =0x03002C6C
	movs r0, #0
	str r0, [r1]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081E21D8: .4byte 0x03002C6C

	thumb_func_start FUN_081e21dc
FUN_081e21dc: @ 0x081E21DC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	bl sound_082402f8
	movs r5, #1
	rsbs r5, r5, #0
	str r5, [r4, #0x50]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E2200
	bl FUN_0823d340
	str r0, [r4, #0x54]
	cmp r0, #0
	beq _081E221C
_081E2200:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r4, #0
	adds r1, #0x6e
	movs r5, #0
	strh r0, [r1]
	ldr r0, _081E2224 @ =0x00001770
	movs r1, #1
	bl LinkConnect_Create
	cmp r0, #0
	bne _081E2228
_081E221C:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E226A
	.align 2, 0
_081E2224: .4byte 0x00001770
_081E2228:
	ldr r1, _081E2270 @ =FUN_081e1a90
	ldr r2, _081E2274 @ =FUN_081e1b40
	adds r0, r4, #0
	bl LinkConnect_SetCallbacks
	adds r0, r4, #0
	bl FUN_081e1a44
	adds r0, r4, #0
	bl FUN_081e19fc
	ldr r0, _081E2278 @ =0x03002C6C
	str r4, [r0]
	str r5, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x80
	str r5, [r0]
	str r5, [r4, #0x78]
	str r5, [r4, #0x74]
	ldr r2, _081E227C @ =FUN_081e20d8
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #7
	strb r0, [r1]
	movs r0, #1
_081E226A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2270: .4byte FUN_081e1a90
_081E2274: .4byte FUN_081e1b40
_081E2278: .4byte 0x03002C6C
_081E227C: .4byte FUN_081e20d8

	thumb_func_start EntityA0A6_Create
EntityA0A6_Create: @ 0x081E2280
	push {r4, lr}
	ldr r0, _081E22B4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E22C2
	movs r0, #2
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E22C0
	ldr r1, _081E22B8 @ =FUN_081e20ec
	ldr r2, _081E22BC @ =FUN_081e21c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e21dc
	cmp r0, #0
	bge _081E22C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E22C2
	.align 2, 0
_081E22B4: .4byte 0x03002C6C
_081E22B8: .4byte FUN_081e20ec
_081E22BC: .4byte FUN_081e21c4
_081E22C0:
	adds r0, r4, #0
_081E22C2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e22c8
FUN_081e22c8: @ 0x081E22C8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [r5, #0x50]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E22EA
	bl FUN_0823d340
	str r0, [r5, #0x54]
	cmp r0, #0
	bne _081E22EA
	adds r0, r4, #0
	b _081E2322
_081E22EA:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r5, #0
	adds r1, #0x6e
	movs r4, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081e1a44
	adds r0, r5, #0
	bl FUN_081e19fc
	ldr r0, _081E2328 @ =0x03002C6C
	str r5, [r0]
	str r4, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0x80
	str r4, [r0]
	str r4, [r5, #0x78]
	str r4, [r5, #0x74]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_081e1a90
	movs r0, #1
_081E2322:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2328: .4byte 0x03002C6C

	thumb_func_start Entity92ED_Create
Entity92ED_Create: @ 0x081E232C
	push {r4, lr}
	ldr r0, _081E2360 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E236E
	movs r0, #2
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E236C
	ldr r1, _081E2364 @ =FUN_081e20ec
	ldr r2, _081E2368 @ =FUN_081e21c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e22c8
	cmp r0, #0
	bge _081E236C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E236E
	.align 2, 0
_081E2360: .4byte 0x03002C6C
_081E2364: .4byte FUN_081e20ec
_081E2368: .4byte FUN_081e21c4
_081E236C:
	adds r0, r4, #0
_081E236E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2374
FUN_081e2374: @ 0x081E2374
	ldr r1, _081E237C @ =0x03002C6C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E237C: .4byte 0x03002C6C

	thumb_func_start FUN_081e2380
FUN_081e2380: @ 0x081E2380
	push {lr}
	ldr r0, _081E2398 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E23A2
	movs r1, #3
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E239C
	movs r0, #1
	b _081E239E
	.align 2, 0
_081E2398: .4byte 0x03002C6C
_081E239C:
	movs r0, #0
_081E239E:
	cmp r0, #0
	bne _081E23A6
_081E23A2:
	movs r0, #0
	b _081E23A8
_081E23A6:
	movs r0, #1
_081E23A8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e23ac
FUN_081e23ac: @ 0x081E23AC
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E23C0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E23BC
	str r1, [r0, #0x74]
	str r1, [r0, #0x7c]
_081E23BC:
	pop {r0}
	bx r0
	.align 2, 0
_081E23C0: .4byte 0x03002C6C

	thumb_func_start FUN_081e23c4
FUN_081e23c4: @ 0x081E23C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E23E0 @ =0x03002C6C
	ldr r3, [r0]
	cmp r3, #0
	beq _081E23DA
	str r4, [r3, #0x7c]
	adds r0, r3, #0
	adds r0, #0x80
	str r1, [r0]
	str r2, [r3, #0x78]
_081E23DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E23E0: .4byte 0x03002C6C

	thumb_func_start FUN_081e23e4
FUN_081e23e4: @ 0x081E23E4
	push {lr}
	ldr r0, _081E23F4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E23F8
	movs r0, #1
	rsbs r0, r0, #0
	b _081E2412
	.align 2, 0
_081E23F4: .4byte 0x03002C6C
_081E23F8:
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2406
	movs r0, #1
	b _081E2408
_081E2406:
	movs r0, #0
_081E2408:
	cmp r0, #0
	bne _081E2410
	movs r0, #0
	b _081E2412
_081E2410:
	movs r0, #1
_081E2412:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e2418
FUN_081e2418: @ 0x081E2418
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E242C @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E2430
	adds r0, #0x60
	strb r1, [r0]
	movs r0, #0
	b _081E2434
	.align 2, 0
_081E242C: .4byte 0x03002C6C
_081E2430:
	movs r0, #1
	rsbs r0, r0, #0
_081E2434:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2438
FUN_081e2438: @ 0x081E2438
	push {lr}
	ldr r0, _081E2448 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E244C
	adds r0, #0x60
	ldrb r0, [r0]
	b _081E244E
	.align 2, 0
_081E2448: .4byte 0x03002C6C
_081E244C:
	movs r0, #0
_081E244E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e2454
FUN_081e2454: @ 0x081E2454
	push {lr}
	ldr r0, _081E2470 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E247A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2474
	movs r0, #1
	b _081E2476
	.align 2, 0
_081E2470: .4byte 0x03002C6C
_081E2474:
	movs r0, #0
_081E2476:
	cmp r0, #0
	bne _081E247E
_081E247A:
	movs r0, #0
	b _081E2480
_081E247E:
	movs r0, #1
_081E2480:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2484
FUN_081e2484: @ 0x081E2484
	push {lr}
	ldr r0, _081E24A0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E24AE
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24A4
	movs r0, #1
	b _081E24A6
	.align 2, 0
_081E24A0: .4byte 0x03002C6C
_081E24A4:
	movs r0, #0
_081E24A6:
	cmp r0, #0
	bne _081E24AE
	movs r0, #0
	b _081E24B0
_081E24AE:
	movs r0, #1
_081E24B0:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e24b4
FUN_081e24b4: @ 0x081E24B4
	push {lr}
	ldr r0, _081E24D0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E2506
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24D4
	movs r0, #1
	b _081E24D6
	.align 2, 0
_081E24D0: .4byte 0x03002C6C
_081E24D4:
	movs r0, #0
_081E24D6:
	cmp r0, #0
	bne _081E2506
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E250C @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	str r3, [r2, #0x4c]
	adds r1, r2, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2506:
	pop {r0}
	bx r0
	.align 2, 0
_081E250C: .4byte FUN_081e1f80

	thumb_func_start FUN_081e2510
FUN_081e2510: @ 0x081E2510
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081E2530 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E253E
	adds r3, r0, #0
	ldr r1, _081E2534 @ =0x00001003
	ldr r0, [r3, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2538
	movs r0, #1
	b _081E253A
	.align 2, 0
_081E2530: .4byte 0x03002C6C
_081E2534: .4byte 0x00001003
_081E2538:
	movs r0, #0
_081E253A:
	cmp r0, #0
	beq _081E2542
_081E253E:
	movs r0, #0
	b _081E25CE
_081E2542:
	cmp r4, #3
	bne _081E2558
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	ldr r0, [r5, #4]
	str r0, [r3, #0x44]
	ldr r0, [r5, #8]
_081E2552:
	str r0, [r3, #0x48]
_081E2554:
	strh r2, [r3, #0x3e]
	b _081E25AA
_081E2558:
	cmp r4, #4
	bne _081E256A
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0xc]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x10]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x14]
	b _081E2552
_081E256A:
	cmp r4, #5
	bne _081E257C
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0x18]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x1c]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x20]
	b _081E2552
_081E257C:
	cmp r4, #0xa
	bne _081E2588
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E2588:
	cmp r4, #0xb
	bne _081E2590
	strh r4, [r3, #0x3c]
	b _081E2554
_081E2590:
	cmp r4, #0xc
	bne _081E259C
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E259C:
	cmp r4, #6
	beq _081E25A8
	cmp r4, #7
	beq _081E25A8
	cmp r4, #8
	bne _081E25CC
_081E25A8:
	strh r4, [r3, #0x3c]
_081E25AA:
	ldr r2, _081E25D4 @ =FUN_081e1d08
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x64]
	ands r0, r1
	str r2, [r3, #0x4c]
	adds r0, r3, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r3, #0x64]
	orrs r0, r1
	str r0, [r3, #0x64]
_081E25CC:
	movs r0, #1
_081E25CE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E25D4: .4byte FUN_081e1d08

	thumb_func_start FUN_081e25d8
FUN_081e25d8: @ 0x081E25D8
	push {lr}
	ldr r0, _081E25EC @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E25E6
	bl KillEntity
_081E25E6:
	pop {r0}
	bx r0
	.align 2, 0
_081E25EC: .4byte 0x03002C6C

	thumb_func_start FUN_081e25f0
FUN_081e25f0: @ 0x081E25F0
	push {lr}
	ldr r0, _081E2608 @ =0x03002C6C
	ldr r2, [r0]
	cmp r2, #0
	beq _081E2604
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2604:
	pop {r0}
	bx r0
	.align 2, 0
_081E2608: .4byte 0x03002C6C

	thumb_func_start FUN_081e260c
FUN_081e260c: @ 0x081E260C
	push {lr}
	ldr r0, _081E2624 @ =0x03002C6C
	ldr r2, [r0]
	cmp r2, #0
	beq _081E2620
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2620:
	pop {r0}
	bx r0
	.align 2, 0
_081E2624: .4byte 0x03002C6C
