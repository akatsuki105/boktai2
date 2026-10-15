	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f9db4
FUN_081f9db4: @ 0x081F9DB4
	push {lr}
	sub sp, #0x10
	ldr r2, _081F9DF4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r1, #0x98
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _081F9DF8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x12
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x88
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #0x78
	movs r2, #0
	movs r3, #0
	bl FUN_081f9b20
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_081F9DF4: .4byte 0xFFFF0000
_081F9DF8: .4byte 0x0000FFFF

	thumb_func_start FUN_081f9dfc
FUN_081f9dfc: @ 0x081F9DFC
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f9e00
FUN_081f9e00: @ 0x081F9E00
	push {r4, r5, lr}
	movs r2, #0
	ldr r1, _081F9E24 @ =0x0000069C
	adds r3, r0, r1
	movs r5, #1
	movs r1, #0x4f
	adds r1, r1, r0
	mov ip, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081F9E14:
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081F9E28
	movs r0, #1
	b _081F9E2A
	.align 2, 0
_081F9E24: .4byte 0x0000069C
_081F9E28:
	movs r0, #0
_081F9E2A:
	cmp r0, #0
	bne _081F9E40
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r0, ip
	strb r2, [r0]
	adds r0, r4, #0
	b _081F9E4E
_081F9E40:
	movs r1, #0x40
	add ip, r1
	adds r4, #0x40
	adds r2, #1
	cmp r2, #0x19
	ble _081F9E14
	movs r0, #0
_081F9E4E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f9e54
FUN_081f9e54: @ 0x081F9E54
	push {lr}
	adds r2, r0, #0
	mov ip, r1
	adds r1, #0x36
	ldrb r0, [r1]
	cmp r0, #0
	bne _081F9E88
	mov r3, ip
	ldrh r0, [r3, #0x3e]
	strb r0, [r1]
	adds r3, #0x37
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strb r0, [r3]
	ldr r1, [r2, #0x18]
	mov r0, ip
	adds r0, #0x3c
	ldrb r2, [r0]
	ldrb r0, [r3]
	adds r2, r2, r0
	mov r0, ip
	bl Particle_SetFrame
	b _081F9E8C
_081F9E88:
	subs r0, #1
	strb r0, [r1]
_081F9E8C:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f9e94
FUN_081f9e94: @ 0x081F9E94
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldrb r0, [r5]
	cmp r0, #0
	beq _081F9EB2
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r0, #0
	strb r0, [r5]
_081F9EB2:
	ldrh r0, [r4, #0x28]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	adds r0, r2, #0
	adds r1, r4, #0
	bl FUN_081f9e54
	ldrh r0, [r4, #0x38]
	cmp r0, #0
	beq _081F9ED6
	subs r0, #1
	strh r0, [r4, #0x38]
	b _081F9EE2
_081F9ED6:
	adds r0, r4, #0
	adds r0, #0x32
	movs r1, #2
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5]
_081F9EE2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f9ee8
FUN_081f9ee8: @ 0x081F9EE8
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F9EF8
	movs r0, #0
	strb r0, [r1]
_081F9EF8:
	ldr r0, _081F9F30 @ =0x03000214
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0x33
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _081F9F34 @ =0x0000069C
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0x32
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl Particle_Remove
	movs r0, #0xff
	strb r0, [r6]
	strh r4, [r5, #0x30]
	strh r4, [r5, #0x38]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F9F30: .4byte 0x03000214
_081F9F34: .4byte 0x0000069C

	thumb_func_start FUN_081f9f38
FUN_081f9f38: @ 0x081F9F38
	push {r4, lr}
	sub sp, #4
	movs r4, #1
	str r4, [sp]
	bl FUN_081f9f60
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f9f4c
FUN_081f9f4c: @ 0x081F9F4C
	push {r4, lr}
	sub sp, #4
	ldr r4, [sp, #0xc]
	str r4, [sp]
	bl FUN_081f9f60
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f9f60
FUN_081f9f60: @ 0x081F9F60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r7, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r0, _081F9F94 @ =0x03000214
	ldr r6, [r0]
	cmp r6, #0
	bne _081F9F82
	bl Entity081fa164_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _081F9F8E
_081F9F82:
	adds r0, r6, #0
	bl FUN_081f9e00
	adds r5, r0, #0
	cmp r5, #0
	bne _081F9F98
_081F9F8E:
	movs r0, #0
	b _081FA070
	.align 2, 0
_081F9F94: .4byte 0x03000214
_081F9F98:
	adds r2, r5, #0
	adds r2, #0x32
	movs r0, #0
	movs r1, #1
	strb r1, [r2]
	movs r2, #0
	strh r0, [r5, #0x30]
	adds r0, r5, #0
	adds r0, #0x34
	strb r1, [r0]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r5, #0x28]
	str r1, [r5, #0x2c]
	mov r0, r8
	strh r0, [r5, #0x38]
	adds r1, r5, #0
	adds r1, #0x35
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x36
	strb r2, [r0]
	adds r3, r0, #0
	cmp r4, #7
	bhi _081FA018
	lsls r0, r4, #2
	ldr r1, _081F9FD8 @ =_081F9FDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081F9FD8: .4byte _081F9FDC
_081F9FDC: @ jump table
	.4byte _081FA018 @ case 0
	.4byte _081F9FFC @ case 1
	.4byte _081FA000 @ case 2
	.4byte _081FA004 @ case 3
	.4byte _081FA008 @ case 4
	.4byte _081FA00C @ case 5
	.4byte _081FA010 @ case 6
	.4byte _081FA014 @ case 7
_081F9FFC:
	movs r1, #1
	b _081FA01A
_081FA000:
	movs r1, #2
	b _081FA01A
_081FA004:
	movs r1, #3
	b _081FA01A
_081FA008:
	movs r1, #4
	b _081FA01A
_081FA00C:
	movs r1, #5
	b _081FA01A
_081FA010:
	movs r1, #6
	b _081FA01A
_081FA014:
	movs r1, #7
	b _081FA01A
_081FA018:
	movs r1, #0
_081FA01A:
	adds r2, r5, #0
	adds r2, #0x37
	movs r0, #0
	strb r0, [r2]
	lsls r0, r1, #1
	adds r4, r5, #0
	adds r4, #0x3c
	strb r0, [r4]
	movs r0, #3
	strh r0, [r5, #0x3e]
	strb r0, [r3]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r1, [r6, #0x18]
	adds r0, r5, #0
	movs r2, #0
	bl Particle_Add
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r6, #0x18]
	ldrb r2, [r4]
	adds r0, r5, #0
	bl Particle_SetFrame
	adds r0, r5, #0
	movs r1, #1
	bl Particle_SetPltt
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r0, [r5, #0xf]
	adds r0, r5, #0
_081FA070:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081fa164_Update
Entity081fa164_Update: @ 0x081FA07C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x1c
	ldr r2, _081FA0B8 @ =0x0000069C
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _081FA0E0
	movs r6, #0
	ldr r0, _081FA0B8 @ =0x0000069C
	adds r0, r0, r7
	mov r8, r0
	ldr r2, _081FA0BC @ =0x085AE5F0
	mov sb, r2
	adds r5, r7, #0
	adds r5, #0x4e
	adds r4, r1, #0
_081FA0A6:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081FA0C0
	movs r0, #1
	b _081FA0C2
	.align 2, 0
_081FA0B8: .4byte 0x0000069C
_081FA0BC: .4byte 0x085AE5F0
_081FA0C0:
	movs r0, #0
_081FA0C2:
	cmp r0, #0
	beq _081FA0D6
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_081FA0D6:
	adds r5, #0x40
	adds r4, #0x40
	adds r6, #1
	cmp r6, #0x19
	ble _081FA0A6
_081FA0E0:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081fa164_Destroy
Entity081fa164_Destroy: @ 0x081FA0F0
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r1, _081FA10C @ =0x0000069C
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081FA0FC:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081FA110
	movs r0, #1
	b _081FA112
	.align 2, 0
_081FA10C: .4byte 0x0000069C
_081FA110:
	movs r0, #0
_081FA112:
	cmp r0, #0
	beq _081FA11C
	adds r0, r4, #0
	bl Particle_Remove
_081FA11C:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #0x19
	ble _081FA0FC
	movs r1, #0
	ldr r0, _081FA134 @ =0x03000214
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081FA134: .4byte 0x03000214

	thumb_func_start Entity081fa164_Init
Entity081fa164_Init: @ 0x081FA138
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081FA158 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r4, #0x18]
	ldr r0, _081FA15C @ =0x0000069C
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _081FA160 @ =0x03000214
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081FA158: .4byte 0x00001C1E
_081FA15C: .4byte 0x0000069C
_081FA160: .4byte 0x03000214

	thumb_func_start Entity081fa164_Create
Entity081fa164_Create: @ 0x081FA164
	push {r4, lr}
	ldr r0, _081FA19C @ =0x03000214
	ldr r0, [r0]
	cmp r0, #0
	bne _081FA1AA
	movs r1, #0xd4
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081FA1A8
	ldr r1, _081FA1A0 @ =Entity081fa164_Update
	ldr r2, _081FA1A4 @ =Entity081fa164_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081fa164_Init
	cmp r0, #0
	bge _081FA1A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081FA1AA
	.align 2, 0
_081FA19C: .4byte 0x03000214
_081FA1A0: .4byte Entity081fa164_Update
_081FA1A4: .4byte Entity081fa164_Destroy
_081FA1A8:
	adds r0, r4, #0
_081FA1AA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081fa1b0
FUN_081fa1b0: @ 0x081FA1B0
	ldr r1, _081FA1B8 @ =0x03000214
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081FA1B8: .4byte 0x03000214
