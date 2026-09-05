	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800a494
FUN_0800a494: @ 0x0800A494
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r6, #0
	adds r4, #0x30
	movs r5, #3
_0800A49E:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0800A49E
	movs r1, #0
	strb r1, [r6]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a4b8
FUN_0800a4b8: @ 0x0800A4B8
	push {r4, r5, r6, lr}
	ldr r0, _0800A4C8 @ =0x03000044
	ldr r5, [r0]
	cmp r5, #0
	bne _0800A4CC
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A4EE
	.align 2, 0
_0800A4C8: .4byte 0x03000044
_0800A4CC:
	adds r4, r5, #0
	adds r4, #0x28
	movs r6, #5
_0800A4D2:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800A4E0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800a494
_0800A4E0:
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _0800A4D2
	movs r0, #0
_0800A4EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a4f4
FUN_0800a4f4: @ 0x0800A4F4
	push {lr}
	bl FUN_0800a4b8
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a500
FUN_0800a500: @ 0x0800A500
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	str r2, [sp, #8]
	ldr r0, [r0, #0x1c]
	movs r1, #1
	mov sl, r1
	ands r1, r0
	mov sl, r1
	movs r1, #3
	mov sb, r1
	ands r1, r0
	mov sb, r1
	movs r6, #0
	adds r5, r7, #0
	adds r5, #8
_0800A52A:
	ldrb r0, [r7, #2]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrb r0, [r5]
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0800A568 @ =0x085AA730
	adds r1, r1, r0
	mov r0, sb
	str r0, [sp]
	ldr r0, [sp, #8]
	str r0, [sp, #4]
	ldr r4, [r1]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	mov r3, sl
	bl _call_via_r4
	adds r5, #0x50
	adds r6, #1
	cmp r6, #3
	ble _0800A52A
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A568: .4byte 0x085AA730

	thumb_func_start Entity0800a89c_Update
Entity0800a89c_Update: @ 0x0800A56C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, _0800A5E8 @ =0x030047A4
	ldr r2, _0800A5EC @ =0x030047A0
	ldr r3, [r0]
	ldr r0, [r2]
	orrs r3, r0
	ands r1, r3
	cmp r1, #0
	beq _0800A59A
	movs r0, #0x80
	lsls r0, r0, #1
	ands r3, r0
	cmp r3, #0
	bne _0800A59A
	b _0800A79C
_0800A59A:
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sb
	ldr r3, [r0]
	ldrh r0, [r3, #0x2c]
	ldr r4, _0800A5F0 @ =0xFFFF0000
	ldr r2, [sp, #0x28]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x28]
	ldrh r1, [r3, #0x2e]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0800A5F4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldrh r2, [r3, #0x30]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	add r3, sp, #0x30
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A5F8
	asrs r0, r0, #8
	b _0800A5FE
	.align 2, 0
_0800A5E8: .4byte 0x030047A4
_0800A5EC: .4byte 0x030047A0
_0800A5F0: .4byte 0xFFFF0000
_0800A5F4: .4byte 0x0000FFFF
_0800A5F8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A5FE:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A610
	asrs r0, r0, #8
	b _0800A616
_0800A610:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A616:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800A62A
	asrs r1, r0, #8
	b _0800A630
_0800A62A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800A630:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
	mov r4, sp
	movs r1, #0x28
	add r1, sb
	mov r8, r1
	mov r7, r8
	movs r2, #5
	mov sl, r2
_0800A646:
	ldrb r0, [r7]
	cmp r0, #0
	bne _0800A64E
	b _0800A77E
_0800A64E:
	ldrb r0, [r7, #2]
	cmp r0, #2
	bne _0800A664
	mov r1, sp
	ldrh r0, [r1, #0x28]
	strh r0, [r4]
	add r1, sp, #0x28
	ldrh r0, [r1, #2]
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	b _0800A6A6
_0800A664:
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800A690
	ldrh r0, [r1, #0x2c]
	adds r0, #0x18
	strh r0, [r4]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #0x30]
	subs r0, #0x18
	b _0800A6A6
_0800A690:
	ldrh r0, [r1, #0x2c]
	subs r0, #0x20
	strh r0, [r4]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #0x30]
	adds r0, #0x20
_0800A6A6:
	strh r0, [r4, #4]
	add r6, sp, #8
	mov r3, sp
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r5, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A6C8
	asrs r0, r0, #8
	b _0800A6CE
_0800A6C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A6CE:
	strh r0, [r6]
	adds r1, r5, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A6E0
	asrs r0, r0, #8
	b _0800A6E6
_0800A6E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A6E6:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800A6FA
	asrs r1, r0, #8
	b _0800A700
_0800A6FA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800A700:
	subs r0, r2, r1
	strh r0, [r6, #2]
	adds r0, r2, r1
	strh r0, [r6, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r4, #8]
	subs r0, #5
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xa]
	subs r0, #5
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0x10]
	adds r0, #5
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x12]
	adds r0, #5
	strh r0, [r4, #0x12]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldrh r0, [r4, #0x18]
	subs r0, #8
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	subs r0, #0x14
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x20]
	adds r0, #8
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x22]
	adds r0, #0x14
	strh r0, [r4, #0x22]
	mov r0, sb
	mov r1, r8
	mov r2, sp
	bl FUN_0800a500
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0800A774
	subs r0, #1
	strb r0, [r7, #4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800A774
	ldrb r0, [r7, #2]
	ldr r1, _0800A7B0 @ =0x085AA724
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
_0800A774:
	ldrh r0, [r7, #6]
	cmp r0, #0
	beq _0800A77E
	subs r0, #1
	strh r0, [r7, #6]
_0800A77E:
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r7, r7, r1
	add r8, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	blt _0800A794
	b _0800A646
_0800A794:
	mov r1, sb
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
_0800A79C:
	movs r0, #0
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A7B0: .4byte 0x085AA724

	thumb_func_start Entity0800a89c_Destroy
Entity0800a89c_Destroy: @ 0x0800A7B4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r2, #0
_0800A7BA:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0x28
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r6, r2, #1
	cmp r0, #0
	beq _0800A7E4
	adds r4, r1, #0
	adds r4, #0x30
	movs r5, #3
_0800A7D6:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0800A7D6
_0800A7E4:
	adds r2, r6, #0
	cmp r2, #5
	ble _0800A7BA
	movs r1, #0
	ldr r0, _0800A7F8 @ =0x03000044
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A7F8: .4byte 0x03000044

	thumb_func_start Entity0800a89c_Init
Entity0800a89c_Init: @ 0x0800A7FC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0800A86C @ =0x03000044
	str r6, [r0]
	ldr r0, _0800A870 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r6, #0x20]
	ldr r0, _0800A874 @ =0x0000922E
	ldr r1, _0800A878 @ =0x0000D1B8
	bl GetFile
	str r0, [r6, #0x24]
	movs r2, #0
_0800A818:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0x28
	adds r0, r6, r0
	movs r1, #0
	strb r1, [r0]
	adds r7, r2, #1
	adds r4, r0, #0
	adds r4, #0x30
	movs r5, #3
_0800A832:
	ldr r1, [r6, #0x20]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0800A832
	adds r2, r7, #0
	cmp r2, #5
	ble _0800A818
	movs r2, #0
	str r2, [r6, #0x1c]
	ldr r0, _0800A87C @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r0, r6, r3
	str r1, [r0]
	cmp r1, #0
	bne _0800A880
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A896
	.align 2, 0
_0800A86C: .4byte 0x03000044
_0800A870: .4byte 0x00001C1A
_0800A874: .4byte 0x0000922E
_0800A878: .4byte 0x0000D1B8
_0800A87C: .4byte 0x03002BE0
_0800A880:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _0800A892
	movs r0, #1
	str r0, [r6, #0x18]
	b _0800A894
_0800A892:
	str r2, [r6, #0x18]
_0800A894:
	movs r0, #0
_0800A896:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity0800a89c_Create
Entity0800a89c_Create: @ 0x0800A89C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0800A8CC @ =0x000007DC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800A8D8
	ldr r1, _0800A8D0 @ =Entity0800a89c_Update
	ldr r2, _0800A8D4 @ =Entity0800a89c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0800a89c_Init
	cmp r0, #0
	bge _0800A8D8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800A8DA
	.align 2, 0
_0800A8CC: .4byte 0x000007DC
_0800A8D0: .4byte Entity0800a89c_Update
_0800A8D4: .4byte Entity0800a89c_Destroy
_0800A8D8:
	adds r0, r4, #0
_0800A8DA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a8e0
FUN_0800a8e0: @ 0x0800A8E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #4]
	adds r4, r1, #0
	adds r5, r2, #0
	str r3, [sp, #8]
	ldr r0, _0800A914 @ =0x03000044
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800A91C
	ldr r0, _0800A918 @ =0x0000FC73
	movs r1, #0
	bl Entity0800a89c_Create
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800A91C
	movs r0, #1
	rsbs r0, r0, #0
	b _0800AC6E
	.align 2, 0
_0800A914: .4byte 0x03000044
_0800A918: .4byte 0x0000FC73
_0800A91C:
	ldr r0, _0800A97C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	bne _0800A926
	b _0800AC6C
_0800A926:
	movs r0, #0xf0
	ands r0, r4
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r3, r1, #0x1f
	movs r0, #0xf
	ands r4, r0
	ldr r0, [sp, #4]
	cmp r0, #4
	ble _0800A93E
	movs r1, #4
	str r1, [sp, #4]
_0800A93E:
	ldr r2, [sp, #0x50]
	cmp r2, #0
	bne _0800A948
	movs r0, #1
	str r0, [sp, #0x50]
_0800A948:
	ldr r0, _0800A980 @ =0x085AA700
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r2, #0
	str r1, [sp, #0x18]
	ldr r1, [sp, #0x10]
	adds r1, #0x28
	str r1, [sp, #0x24]
	str r1, [sp, #0x20]
_0800A95E:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800A968
	b _0800AC54
_0800A968:
	strb r4, [r1, #2]
	strb r5, [r1, #3]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r1, #1]
	cmp r3, #0
	beq _0800A984
	strb r0, [r1, #4]
	b _0800A98A
	.align 2, 0
_0800A97C: .4byte 0x03002BE0
_0800A980: .4byte 0x085AA700
_0800A984:
	movs r0, #0xe
	ldr r3, [sp, #0x20]
	strb r0, [r3, #4]
_0800A98A:
	movs r0, #0
	str r0, [sp, #0x14]
	mov sl, r0
	ldr r1, [sp, #4]
	cmp sl, r1
	blt _0800A998
	b _0800AC1A
_0800A998:
	ldr r7, _0800AB4C @ =0x030046B8
	ldr r5, [sp, #0x24]
	adds r5, #0x10
	ldr r2, [sp, #0x24]
	adds r2, #0x20
	mov sb, r2
	ldr r3, [sp, #0x24]
	adds r3, #8
	mov r8, r3
	ldr r0, [sp, #0x24]
	adds r0, #0x30
	str r0, [sp, #0x1c]
	mov sl, r1
_0800A9B2:
	movs r2, #1
	mov r1, r8
	strb r2, [r1]
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0x50]
	bl Mod
	ldr r2, [sp, #0x4c]
	adds r0, r2, r0
	mov r3, r8
	strh r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r3, #6]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0800AB50 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0800AB54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r3, #1]
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strb r0, [r1, #2]
	ldr r0, [r7]
	adds r0, #1
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x80
	rsbs r1, r1, #0
	orrs r0, r1
	mov r2, r8
	strb r0, [r2, #3]
	ldr r0, [r5, #0x20]
	adds r1, #0x7e
	ands r0, r1
	str r0, [r5, #0x20]
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	strh r0, [r5, #0x38]
	ldr r1, [sp, #0x48]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0800AA5E
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x48]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Mod
	ldrh r1, [r5, #0x38]
	adds r1, r1, r0
	strh r1, [r5, #0x38]
_0800AA5E:
	ldr r1, [sp, #8]
	ldrh r0, [r1, #2]
	strh r0, [r5, #0x3a]
	ldr r2, [sp, #0x48]
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _0800AA90
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0800AB50 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0800AB54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, [sp, #0x48]
	movs r2, #2
	ldrsh r1, [r3, r2]
	bl Mod
	ldrh r1, [r5, #0x3a]
	adds r1, r1, r0
	strh r1, [r5, #0x3a]
_0800AA90:
	ldr r3, [sp, #8]
	ldrh r0, [r3, #4]
	strh r0, [r5, #0x3c]
	ldr r1, [sp, #0x48]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0800AAC2
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x48]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl Mod
	ldrh r1, [r5, #0x3c]
	adds r1, r1, r0
	strh r1, [r5, #0x3c]
_0800AAC2:
	ldr r0, [sp, #0x10]
	ldr r1, [r0, #0x24]
	ldr r3, _0800AB58 @ =0x085AA6D0
	ldr r2, [r0, #0x18]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, [sp, #0x18]
	adds r0, r2, r0
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r3, #0
	str r3, [sp]
	mov r0, sb
	bl FUN_08236fac
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r5, #0x18]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	cmp r1, #2
	ble _0800AAF6
	movs r2, #0
	str r2, [sp, #0x14]
_0800AAF6:
	movs r3, #0
	strh r3, [r5]
	strh r3, [r5, #2]
	strh r3, [r5, #4]
	ldr r0, [r5, #0x38]
	ldr r1, [r5, #0x3c]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x20]
	mov ip, r0
	mov r4, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x10]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r1, ip
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x28]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0800AB5C
	ldr r0, [r5, #0x20]
	movs r1, #4
	orrs r0, r1
	b _0800AB64
	.align 2, 0
_0800AB4C: .4byte 0x030046B8
_0800AB50: .4byte 0x000003FF
_0800AB54: .4byte 0x0203B400
_0800AB58: .4byte 0x085AA6D0
_0800AB5C:
	ldr r0, [r5, #0x20]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800AB64:
	str r0, [r5, #0x20]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800AB88
	ldr r0, [r5, #0x20]
	movs r1, #8
	orrs r0, r1
	b _0800AB90
_0800AB88:
	ldr r0, [r5, #0x20]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800AB90:
	str r0, [r5, #0x20]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0800ABC8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0800ABF2
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800ABCC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800ABC0
	ldrb r0, [r4, #5]
_0800ABC0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800ABDC
	.align 2, 0
_0800ABC8: .4byte 0x0000FFFF
_0800ABCC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800ABDC
	strh r1, [r4, #8]
_0800ABDC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0800ABF2:
	ldr r0, [sp, #0x1c]
	movs r1, #0
	bl FUN_0822da50
	adds r5, #0x50
	movs r3, #0x50
	add sb, r3
	add r8, r3
	ldr r0, [sp, #0x1c]
	adds r0, #0x50
	str r0, [sp, #0x1c]
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r2, sl
	cmp r2, #0
	beq _0800AC16
	b _0800A9B2
_0800AC16:
	ldr r3, [sp, #4]
	mov sl, r3
_0800AC1A:
	mov r0, sl
	cmp r0, #3
	bgt _0800AC48
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #4
	adds r0, #0x30
	ldr r1, [sp, #0x24]
	adds r4, r0, r1
_0800AC2C:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822da50
	adds r4, #0x50
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _0800AC2C
_0800AC48:
	movs r0, #0x28
	ldr r1, [sp, #0x20]
	strh r0, [r1, #6]
	movs r0, #1
	strb r0, [r1]
	b _0800AC6C
_0800AC54:
	ldr r0, [sp, #0x20]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	adds r0, r0, r1
	str r0, [sp, #0x24]
	adds r2, #1
	cmp r2, #5
	bgt _0800AC6C
	b _0800A95E
_0800AC6C:
	movs r0, #0
_0800AC6E:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ac80
FUN_0800ac80: @ 0x0800AC80
  .include "asm/func/FUN_0800ac80.inc"

