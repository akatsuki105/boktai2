	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081e9f78
FUN_081e9f78: @ 0x081E9F78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, r1
	str r2, [sp, #4]
	cmp r0, #0
	beq _081E9F96
	ldr r0, _081E9F9C @ =0x030001B8
	ldr r6, [r0]
	cmp r6, #0
	bne _081E9FA0
_081E9F96:
	movs r0, #1
	rsbs r0, r0, #0
	b _081EA01E
	.align 2, 0
_081E9F9C: .4byte 0x030001B8
_081E9FA0:
	movs r7, #0
	cmp r7, r8
	bge _081EA01C
	movs r0, #1
	mov sl, r0
	lsls r3, r3, #0x10
	str r3, [sp, #8]
_081E9FAE:
	adds r0, r6, #0
	bl FUN_081e9f28
	adds r5, r0, #0
	cmp r5, #0
	beq _081E9F96
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	adds r4, r1, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r6, r4
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5]
	str r1, [r5, #4]
	adds r0, r4, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	lsls r0, r0, #4
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, [r6, #0x18]
	movs r2, #0
	str r2, [sp]
	ldr r3, [sp, #8]
	lsrs r2, r3, #0x10
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4, #0xc]
	ldr r1, [sp, #0x2c]
	bl Video_SetAuxSpritePltt
	ldr r0, [r4]
	mov r1, sl
	orrs r0, r1
	str r0, [r4]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r4, #7]
	strb r1, [r5, #0xa]
	adds r7, #1
	cmp r7, r8
	blt _081E9FAE
_081EA01C:
	movs r0, #0
_081EA01E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081ea120_Update
Entity081ea120_Update: @ 0x081EA030
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EA08A
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r4, r6, r1
	ldr r0, _081EA068 @ =0x085AE45C
	mov r8, r0
_081EA056:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA06C
	movs r0, #1
	b _081EA06E
	.align 2, 0
_081EA068: .4byte 0x085AE45C
_081EA06C:
	movs r0, #0
_081EA06E:
	cmp r0, #0
	beq _081EA082
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EA082:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA056
_081EA08A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081ea120_Destroy
Entity081ea120_Destroy: @ 0x081EA098
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	adds r0, #4
	adds r4, r6, r0
_081EA0A8:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA0B8
	movs r0, #1
	b _081EA0BA
_081EA0B8:
	movs r0, #0
_081EA0BA:
	cmp r0, #0
	beq _081EA0CE
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r6, r0
	bl AuxSprite_Remove
_081EA0CE:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA0A8
	movs r1, #0
	ldr r0, _081EA0E4 @ =0x030001B8
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA0E4: .4byte 0x030001B8

	thumb_func_start FUN_081ea0e8
FUN_081ea0e8: @ 0x081EA0E8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _081EA108 @ =0x0000863A
	bl Video_GetAuxSprite
	ldr r0, _081EA10C @ =0x0000922E
	ldr r1, _081EA110 @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081EA108: .4byte 0x0000863A
_081EA10C: .4byte 0x0000922E
_081EA110: .4byte 0x0000931E

	thumb_func_start Entity081ea120_Init
Entity081ea120_Init: @ 0x081EA114
	push {lr}
	bl FUN_081ea0e8
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start Entity081ea120_Create
Entity081ea120_Create: @ 0x081EA120
	push {r4, r5, lr}
	ldr r5, _081EA15C @ =0x030001B8
	ldr r0, [r5]
	cmp r0, #0
	bne _081EA16A
	movs r1, #0x9f
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _081EA168
	ldr r1, _081EA160 @ =Entity081ea120_Update
	ldr r2, _081EA164 @ =Entity081ea120_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl Entity081ea120_Init
	cmp r0, #0
	bge _081EA168
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA16A
	.align 2, 0
_081EA15C: .4byte 0x030001B8
_081EA160: .4byte Entity081ea120_Update
_081EA164: .4byte Entity081ea120_Destroy
_081EA168:
	adds r0, r4, #0
_081EA16A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea170
FUN_081ea170: @ 0x081EA170
	ldr r1, _081EA178 @ =0x030001B8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EA178: .4byte 0x030001B8

	thumb_func_start FUN_081ea17c
FUN_081ea17c: @ 0x081EA17C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea180
FUN_081ea180: @ 0x081EA180
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea184
FUN_081ea184: @ 0x081EA184
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r7, [sp, #0x38]
	ldr r2, _081EA210 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081EA214 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _081EA218 @ =0x00002001
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081EA21C @ =FUN_081ea180
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EA210: .4byte 0xFFFF0000
_081EA214: .4byte 0x0000FFFF
_081EA218: .4byte 0x00002001
_081EA21C: .4byte FUN_081ea180

	thumb_func_start FUN_081ea220
FUN_081ea220: @ 0x081EA220
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081EA228:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x34]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081EA23A
	movs r0, #1
	b _081EA23C
_081EA23A:
	movs r0, #0
_081EA23C:
	cmp r0, #0
	bne _081EA258
	movs r0, #0xd4
	muls r0, r2, r0
	adds r0, #0x38
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x34]
	adds r1, r0, #0
	adds r1, #0xd3
	strb r2, [r1]
	b _081EA260
_081EA258:
	adds r2, #1
	cmp r2, #7
	ble _081EA228
	movs r0, #0
_081EA260:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea268
FUN_081ea268: @ 0x081EA268
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r7, r1, #0
	mov sb, r7
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldrh r0, [r7, #0x34]
	ldrh r1, [r7, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x36]
	ldrh r2, [r7, #0x2e]
	adds r0, r1, r2
	strh r0, [r7, #0x2e]
	ldrh r0, [r7, #0x38]
	ldrh r2, [r7, #0x30]
	adds r0, r0, r2
	strh r0, [r7, #0x30]
	subs r1, #1
	strh r1, [r7, #0x36]
	movs r0, #0x1e
	ldrsh r6, [r7, r0]
	adds r5, r7, #0
	adds r5, #0x1c
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081EA2D4
	cmp r1, #0
	blt _081EA2D4
	ldr r0, _081EA2D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EA2D4
	ldr r0, _081EA2DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EA2E0
_081EA2D4:
	movs r4, #0
	b _081EA2EE
	.align 2, 0
_081EA2D8: .4byte 0x030046A8
_081EA2DC: .4byte 0x030046AC
_081EA2E0:
	ldr r0, _081EA300 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081EA2EE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081EA304
	adds r0, #4
	b _081EA310
	.align 2, 0
_081EA300: .4byte 0x030046A4
_081EA304:
	ldr r0, _081EA324 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EA310:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EA328
	cmp r2, #2
	beq _081EA32C
	b _081EA330
	.align 2, 0
_081EA324: .4byte 0x030046A4
_081EA328:
	ldrb r0, [r5, #4]
	b _081EA32E
_081EA32C:
	ldrb r0, [r5]
_081EA32E:
	subs r1, r1, r0
_081EA330:
	cmp r6, r1
	blo _081EA33E
	mov r1, sb
	movs r2, #0x1e
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _081EA424
_081EA33E:
	movs r0, #0xeb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r5, r7, #0
	adds r5, #0xd3
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r7, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	mov r0, sb
	bl AuxSprite_Remove
	adds r0, r7, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
	adds r0, r7, #0
	adds r0, #0xd0
	strh r4, [r0]
	subs r0, #4
	str r4, [r0]
	ldr r5, _081EA40C @ =0xFFFF0000
	ldr r4, [sp, #0xc]
	ands r4, r5
	ldr r6, _081EA410 @ =0x0000FFF4
	orrs r4, r6
	str r4, [sp, #0xc]
	ldr r0, _081EA414 @ =0x0203B400
	mov ip, r0
	ldr r1, _081EA418 @ =0x030046B8
	mov sl, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r2, _081EA41C @ =0x000003FF
	mov r8, r2
	ands r1, r2
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	movs r0, #7
	mov sb, r0
	mov r0, sb
	ands r2, r0
	lsls r2, r2, #0x10
	ldr r3, _081EA420 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r6
	str r0, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ands r2, r5
	movs r4, #0x18
	orrs r2, r4
	str r2, [sp, #0x14]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	mov r0, sl
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	mov r1, sb
	ands r0, r1
	adds r0, #3
	lsls r0, r0, #0x10
	ands r3, r2
	orrs r3, r0
	str r3, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r4
	str r0, [r1, #4]
	adds r2, r7, #0
	adds r2, #0x2c
	str r1, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x1f
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
	b _081EA43A
	.align 2, 0
_081EA40C: .4byte 0xFFFF0000
_081EA410: .4byte 0x0000FFF4
_081EA414: .4byte 0x0203B400
_081EA418: .4byte 0x030046B8
_081EA41C: .4byte 0x000003FF
_081EA420: .4byte 0x0000FFFF
_081EA424:
	adds r4, r7, #0
	adds r4, #0x3c
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081EA43A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ea44c
FUN_081ea44c: @ 0x081EA44C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081EA46E
	movs r2, #0
	cmp r0, #0x28
	ble _081EA46E
	movs r2, #1
_081EA46E:
	adds r4, r5, #0
	adds r4, #0xcc
	ldr r0, [r4]
	ldr r1, _081EA498 @ =0x085AE468
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	adds r7, r4, #0
	cmp r0, #0
	bne _081EA4A0
	ldr r1, [r6]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081EA49C
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EA49E
	.align 2, 0
_081EA498: .4byte 0x085AE468
_081EA49C:
	orrs r1, r2
_081EA49E:
	str r1, [r6]
_081EA4A0:
	ldr r0, [r7]
	cmp r0, #0x5a
	ble _081EA4E4
	movs r0, #0xd3
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r5, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	strh r4, [r0]
	str r4, [r7]
	b _081EA4E8
_081EA4E4:
	adds r0, #1
	str r0, [r7]
_081EA4E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ea4f4
FUN_081ea4f4: @ 0x081EA4F4
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _081EA518
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081EA51E
_081EA518:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081EA51E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ea524
FUN_081ea524: @ 0x081EA524
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	ldr r6, [sp, #0x24]
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	bl FUN_081ea688
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea540
FUN_081ea540: @ 0x081EA540
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	mov sl, r1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldrh r1, [r1, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r7, _081EA670 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sl
	ldrh r1, [r0, #0xc]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r6, sp, #0xc
	ldr r0, [sp, #0x10]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _081EA674 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081EA678 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r0, r0, r2
	ldrh r4, [r0]
	movs r0, #0x3f
	ands r4, r0
	adds r4, #0x1e
	adds r0, r6, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0xc]
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #2
	bl Div
	ldr r1, [r5]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	str r1, [r5]
	lsls r1, r1, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #7
	ands r1, r2
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _081EA680 @ =0x0000FFFF
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x30
	ble _081EA60A
	adds r0, r7, #0
	ands r0, r2
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA60A:
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081EA622
	ldr r0, [sp, #0xc]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA622:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0x30
	ble _081EA634
	ldr r0, [sp, #0x10]
	ands r0, r7
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA634:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bge _081EA646
	ldr r0, [sp, #0x10]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA646:
	ldr r2, [sp, #0x18]
	str r2, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	str r0, [sp, #8]
	mov r0, sb
	mov r1, sl
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	bl FUN_081ea688
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA670: .4byte 0xFFFF0000
_081EA674: .4byte 0x030046B8
_081EA678: .4byte 0x000003FF
_081EA67C: .4byte 0x0203B400
_081EA680: .4byte 0x0000FFFF
_081EA684: .4byte 0x0000FFD0
