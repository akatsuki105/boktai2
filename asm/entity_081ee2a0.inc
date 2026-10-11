	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081edd1c
FUN_081edd1c: @ 0x081EDD1C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081edd20
FUN_081edd20: @ 0x081EDD20
	push {r4, r5, lr}
	movs r2, #0
	ldr r1, _081EDD44 @ =0x0000069C
	adds r3, r0, r1
	movs r5, #1
	movs r1, #0x4f
	adds r1, r1, r0
	mov ip, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EDD34:
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081EDD48
	movs r0, #1
	b _081EDD4A
	.align 2, 0
_081EDD44: .4byte 0x0000069C
_081EDD48:
	movs r0, #0
_081EDD4A:
	cmp r0, #0
	bne _081EDD60
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r0, ip
	strb r2, [r0]
	adds r0, r4, #0
	b _081EDD6E
_081EDD60:
	movs r1, #0x40
	add ip, r1
	adds r4, #0x40
	adds r2, #1
	cmp r2, #0x19
	ble _081EDD34
	movs r0, #0
_081EDD6E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081edd74
FUN_081edd74: @ 0x081EDD74
	push {lr}
	adds r2, r0, #0
	mov ip, r1
	adds r1, #0x36
	ldrb r0, [r1]
	cmp r0, #0
	beq _081EDD88
	subs r0, #1
	strb r0, [r1]
	b _081EDDAC
_081EDD88:
	movs r0, #3
	strb r0, [r1]
	mov r3, ip
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
_081EDDAC:
	pop {r0}
	bx r0

	thumb_func_start FUN_081eddb0
FUN_081eddb0: @ 0x081EDDB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	adds r6, r1, #0
	adds r2, r6, #0
	adds r2, #0x34
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EDDD8
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r0, #0
	strb r0, [r2]
_081EDDD8:
	ldrh r1, [r6, #0x30]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081EDDE4
	b _081EDFFA
_081EDDE4:
	adds r0, r6, #0
	adds r0, #0x18
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r3, r0, #0
	cmp r2, #0
	blt _081EDE0E
	cmp r1, #0
	blt _081EDE0E
	ldr r0, _081EDE14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EDE0E
	ldr r0, _081EDE18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EDE1C
_081EDE0E:
	movs r0, #0
	b _081EDE2A
	.align 2, 0
_081EDE14: .4byte 0x030046A8
_081EDE18: .4byte 0x030046AC
_081EDE1C:
	ldr r0, _081EDE58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081EDE2A:
	strh r0, [r6, #0x3a]
	ldrh r0, [r6, #0x2a]
	subs r0, #1
	strh r0, [r6, #0x2a]
	adds r7, r3, #0
	adds r4, r6, #0
	adds r4, #0x28
	ldrh r0, [r6, #0x3a]
	mov r8, r0
	movs r1, #0x28
	ldrsh r0, [r6, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	mov r0, r8
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EDE5C
	adds r0, #4
	b _081EDE6A
	.align 2, 0
_081EDE58: .4byte 0x030046A4
_081EDE5C:
	ldr r0, _081EDE80 @ =0x030046A4
	ldr r1, [r0]
	mov r3, r8
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EDE6A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EDE84
	cmp r2, #2
	beq _081EDE88
	b _081EDE8C
	.align 2, 0
_081EDE80: .4byte 0x030046A4
_081EDE84:
	ldrb r0, [r7, #4]
	b _081EDE8A
_081EDE88:
	ldrb r0, [r7]
_081EDE8A:
	subs r1, r1, r0
_081EDE8C:
	mov sb, r1
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	cmn r1, r0
	bne _081EDEB4
	movs r0, #1
	b _081EDFEE
_081EDEB4:
	movs r1, #2
	ldrsh r0, [r7, r1]
	cmp r0, sb
	bgt _081EDEF0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	rsbs r0, r0, #0
	movs r1, #0xa
	bl Div
	strh r0, [r4, #2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r4, #4]
	mov r0, sb
	strh r0, [r7, #2]
_081EDEF0:
	ldrh r0, [r4]
	ldrh r1, [r7]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, _081EDF48 @ =0xFFFF0000
	ldrh r1, [r4, #2]
	ldrh r2, [r7, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, #4]
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sp
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _081EDF42
	cmp r1, #0
	blt _081EDF42
	ldr r0, _081EDF4C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081EDF42
	ldr r0, _081EDF50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EDF54
_081EDF42:
	movs r5, #0
	b _081EDF62
	.align 2, 0
_081EDF48: .4byte 0xFFFF0000
_081EDF4C: .4byte 0x030046A8
_081EDF50: .4byte 0x030046AC
_081EDF54:
	ldr r0, _081EDF78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_081EDF62:
	cmp r8, r5
	beq _081EDFD4
	mov r8, sp
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EDF7C
	adds r0, #4
	b _081EDF88
	.align 2, 0
_081EDF78: .4byte 0x030046A4
_081EDF7C:
	ldr r0, _081EDF9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EDF88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EDFA0
	cmp r2, #2
	beq _081EDFA6
	b _081EDFAC
	.align 2, 0
_081EDF9C: .4byte 0x030046A4
_081EDFA0:
	mov r2, r8
	ldrb r0, [r2, #4]
	b _081EDFAA
_081EDFA6:
	mov r3, r8
	ldrb r0, [r3]
_081EDFAA:
	subs r1, r1, r0
_081EDFAC:
	cmp sb, r1
	bge _081EDFD4
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r2, #4
	ldrsh r1, [r4, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #4]
_081EDFD4:
	ldrh r0, [r4]
	ldrh r3, [r7]
	adds r0, r0, r3
	strh r0, [r7]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r7, #4]
	movs r0, #0
_081EDFEE:
	cmp r0, #0
	beq _081EDFFA
	ldrh r1, [r6, #0x30]
	movs r0, #1
	orrs r0, r1
	strh r0, [r6, #0x30]
_081EDFFA:
	mov r0, sl
	adds r1, r6, #0
	bl FUN_081edd74
	ldrh r0, [r6, #0x38]
	cmp r0, #0
	beq _081EE00E
	subs r0, #1
	strh r0, [r6, #0x38]
	b _081EE01C
_081EE00E:
	adds r1, r6, #0
	adds r1, #0x32
	movs r0, #2
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
_081EE01C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ee02c
FUN_081ee02c: @ 0x081EE02C
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0
	beq _081EE03C
	movs r0, #0
	strb r0, [r1]
_081EE03C:
	ldr r0, _081EE074 @ =0x030001CC
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0x33
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _081EE078 @ =0x0000069C
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
_081EE074: .4byte 0x030001CC
_081EE078: .4byte 0x0000069C

	thumb_func_start FUN_081ee07c
FUN_081ee07c: @ 0x081EE07C
	push {r4, lr}
	sub sp, #4
	movs r4, #1
	str r4, [sp]
	bl FUN_081ee0a4
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ee090
FUN_081ee090: @ 0x081EE090
	push {r4, lr}
	sub sp, #4
	ldr r4, [sp, #0xc]
	str r4, [sp]
	bl FUN_081ee0a4
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ee0a4
FUN_081ee0a4: @ 0x081EE0A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r7, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r0, _081EE0D8 @ =0x030001CC
	ldr r6, [r0]
	cmp r6, #0
	bne _081EE0C6
	bl Entity081ee2a0_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _081EE0D2
_081EE0C6:
	adds r0, r6, #0
	bl FUN_081edd20
	adds r5, r0, #0
	cmp r5, #0
	bne _081EE0DC
_081EE0D2:
	movs r0, #0
	b _081EE1AA
	.align 2, 0
_081EE0D8: .4byte 0x030001CC
_081EE0DC:
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
	cmp r4, #7
	bhi _081EE158
	lsls r0, r4, #2
	ldr r1, _081EE118 @ =_081EE11C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081EE118: .4byte _081EE11C
_081EE11C: @ jump table
	.4byte _081EE158 @ case 0
	.4byte _081EE13C @ case 1
	.4byte _081EE140 @ case 2
	.4byte _081EE144 @ case 3
	.4byte _081EE148 @ case 4
	.4byte _081EE14C @ case 5
	.4byte _081EE150 @ case 6
	.4byte _081EE154 @ case 7
_081EE13C:
	movs r1, #1
	b _081EE15A
_081EE140:
	movs r1, #2
	b _081EE15A
_081EE144:
	movs r1, #3
	b _081EE15A
_081EE148:
	movs r1, #4
	b _081EE15A
_081EE14C:
	movs r1, #5
	b _081EE15A
_081EE150:
	movs r1, #6
	b _081EE15A
_081EE154:
	movs r1, #7
	b _081EE15A
_081EE158:
	movs r1, #0
_081EE15A:
	adds r2, r5, #0
	adds r2, #0x37
	movs r0, #0
	strb r0, [r2]
	lsls r0, r1, #1
	adds r4, r5, #0
	adds r4, #0x3c
	strb r0, [r4]
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
_081EE1AA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081ee2a0_Update
Entity081ee2a0_Update: @ 0x081EE1B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x1c
	ldr r2, _081EE1F4 @ =0x0000069C
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _081EE21C
	movs r6, #0
	ldr r0, _081EE1F4 @ =0x0000069C
	adds r0, r0, r7
	mov r8, r0
	ldr r2, _081EE1F8 @ =0x085AE4C8
	mov sb, r2
	adds r5, r7, #0
	adds r5, #0x4e
	adds r4, r1, #0
_081EE1E2:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081EE1FC
	movs r0, #1
	b _081EE1FE
	.align 2, 0
_081EE1F4: .4byte 0x0000069C
_081EE1F8: .4byte 0x085AE4C8
_081EE1FC:
	movs r0, #0
_081EE1FE:
	cmp r0, #0
	beq _081EE212
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EE212:
	adds r5, #0x40
	adds r4, #0x40
	adds r6, #1
	cmp r6, #0x19
	ble _081EE1E2
_081EE21C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081ee2a0_Destroy
Entity081ee2a0_Destroy: @ 0x081EE22C
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r1, _081EE248 @ =0x0000069C
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EE238:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EE24C
	movs r0, #1
	b _081EE24E
	.align 2, 0
_081EE248: .4byte 0x0000069C
_081EE24C:
	movs r0, #0
_081EE24E:
	cmp r0, #0
	beq _081EE258
	adds r0, r4, #0
	bl Particle_Remove
_081EE258:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #0x19
	ble _081EE238
	movs r1, #0
	ldr r0, _081EE270 @ =0x030001CC
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EE270: .4byte 0x030001CC

	thumb_func_start Entity081ee2a0_Init
Entity081ee2a0_Init: @ 0x081EE274
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081EE294 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r4, #0x18]
	ldr r0, _081EE298 @ =0x0000069C
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _081EE29C @ =0x030001CC
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081EE294: .4byte 0x00001C1E
_081EE298: .4byte 0x0000069C
_081EE29C: .4byte 0x030001CC

	thumb_func_start Entity081ee2a0_Create
Entity081ee2a0_Create: @ 0x081EE2A0
	push {r4, lr}
	ldr r0, _081EE2D8 @ =0x030001CC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EE2E6
	movs r1, #0xd4
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EE2E4
	ldr r1, _081EE2DC @ =Entity081ee2a0_Update
	ldr r2, _081EE2E0 @ =Entity081ee2a0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081ee2a0_Init
	cmp r0, #0
	bge _081EE2E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EE2E6
	.align 2, 0
_081EE2D8: .4byte 0x030001CC
_081EE2DC: .4byte Entity081ee2a0_Update
_081EE2E0: .4byte Entity081ee2a0_Destroy
_081EE2E4:
	adds r0, r4, #0
_081EE2E6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ee2ec
FUN_081ee2ec: @ 0x081EE2EC
	ldr r1, _081EE2F4 @ =0x030001CC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EE2F4: .4byte 0x030001CC
