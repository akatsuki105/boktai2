	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cbb2c
FUN_080cbb2c: @ 0x080CBB2C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r3, r0, #0
	mov r2, sp
	ldr r0, _080CBB64 @ =0x08251E08
	ldm r0!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r0, #0
	strh r1, [r2]
	movs r4, #0x9b
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	movs r5, #0x9c
	lsls r5, r5, #1
	adds r1, r3, r5
	ldrh r0, [r2]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CBB64: .4byte 0x08251E08

	thumb_func_start FUN_080cbb68
FUN_080cbb68: @ 0x080CBB68
	push {r4, lr}
	sub sp, #0x10
	adds r3, r1, #0
	ldr r4, [r0, #0x38]
	cmp r3, #0
	bne _080CBBB4
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #2
	beq _080CBBD4
	cmp r2, #0
	ble _080CBBA6
	ldr r1, _080CBBB0 @ =0xFFFF0000
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0xb8
	adds r3, r4, #0
	adds r3, #0x24
	add r1, sp, #8
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_0805fe7c
_080CBBA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cbb2c
	b _080CBBD4
	.align 2, 0
_080CBBB0: .4byte 0xFFFF0000
_080CBBB4:
	cmp r3, #1
	bne _080CBBD4
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1, #4]
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080cbb2c
_080CBBD4:
	movs r0, #1
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cbbe0
FUN_080cbbe0: @ 0x080CBBE0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x21
	ldrb r2, [r3]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r7, [r0]
	cmp r2, r7
	beq _080CBC10
	ldrh r0, [r0]
	subs r0, r0, r2
	subs r1, #0x2c
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080CBC0A
	adds r0, r2, #4
	b _080CBC0E
_080CBC0A:
	adds r0, r2, #0
	adds r0, #0xfc
_080CBC0E:
	strb r0, [r3]
_080CBC10:
	movs r7, #0x97
	lsls r7, r7, #1
	adds r7, r7, r6
	mov ip, r7
	ldrh r0, [r7]
	cmp r0, #0
	bne _080CBC64
	ldr r5, _080CBC58 @ =0x0203B400
	ldr r4, _080CBC5C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _080CBC60 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	movs r7, #0x96
	lsls r7, r7, #1
	adds r2, r6, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x78
	mov r1, ip
	strh r0, [r1]
	b _080CBC6A
	.align 2, 0
_080CBC58: .4byte 0x0203B400
_080CBC5C: .4byte 0x030046B8
_080CBC60: .4byte 0x000003FF
_080CBC64:
	subs r0, #1
	mov r7, ip
	strh r0, [r7]
_080CBC6A:
	adds r4, r6, #0
	adds r4, #0xb8
	adds r1, r6, #0
	adds r1, #0x24
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #7
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cbc90
FUN_080cbc90: @ 0x080CBC90
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bhi _080CBCAC
	adds r0, r4, #0
	adds r0, #0x8c
	subs r1, #4
	bl Video_SetAuxSpritePltt
	b _080CBCB6
_080CBCAC:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, _080CBCD4 @ =0x00000133
	bl Video_SetAuxSpritePltt
_080CBCB6:
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	movs r0, #0x9b
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CBCD4: .4byte 0x00000133

	thumb_func_start FUN_080cbcd8
FUN_080cbcd8: @ 0x080CBCD8
	push {r4, lr}
	mov ip, r0
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, ip
	movs r1, #2
	strh r1, [r0]
	movs r1, #0x99
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CBD62
	adds r4, r0, #0
	ldr r2, _080CBD14 @ =0x085B0A08
	mov r3, ip
	adds r3, #0x21
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CBD18
	asrs r4, r0, #0xc
	b _080CBD1E
	.align 2, 0
_080CBD14: .4byte 0x085B0A08
_080CBD18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080CBD1E:
	mov r1, ip
	ldrh r0, [r1, #0x2c]
	adds r0, r0, r4
	strh r0, [r1, #0x2c]
	movs r0, #0x99
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080CBD42
	asrs r1, r0, #0xc
	b _080CBD48
_080CBD42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CBD48:
	mov r2, ip
	ldrh r0, [r2, #0x30]
	adds r0, r0, r1
	strh r0, [r2, #0x30]
	movs r2, #0x99
	lsls r2, r2, #1
	add r2, ip
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080CBD8E
_080CBD62:
	mov r1, ip
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #0x80
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #0x96
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	add r2, ip
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #4]
	ands r0, r1
	str r0, [r2, #4]
	mov r0, ip
	movs r1, #0
	bl FUN_080cbb2c
_080CBD8E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cbd94
FUN_080cbd94: @ 0x080CBD94
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0x21
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	ands r0, r3
	cmp r0, #1
	ble _080CBDB6
	subs r3, r3, r0
	movs r6, #1
	b _080CBDBA
_080CBDB6:
	adds r3, r0, #0
	movs r6, #0
_080CBDBA:
	movs r0, #0x84
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r6, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x60
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080CBE0C
	ldr r0, [r5, #0x60]
	movs r1, #4
	orrs r0, r1
	b _080CBE14
_080CBE0C:
	ldr r0, [r5, #0x60]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CBE14:
	str r0, [r5, #0x60]
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
	beq _080CBE38
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080CBE40
_080CBE38:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CBE40:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CBE78 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CBEB0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CBE7C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CBE70
	ldrb r0, [r4, #5]
_080CBE70:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CBE8C
	.align 2, 0
_080CBE78: .4byte 0x0000FFFF
_080CBE7C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CBE8C
	strh r1, [r4, #8]
_080CBE8C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CBEB0
	movs r0, #1
	strb r0, [r4, #7]
_080CBEB0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start EntityF41A_Update
EntityF41A_Update: @ 0x080CBEB8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080cbd94
	adds r4, #0x1c
	adds r0, r4, #0
	bl FUN_0823b4b8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityF41A_Destroy
EntityF41A_Destroy: @ 0x080CBEE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0823b284
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0807f598
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cbf04
FUN_080cbf04: @ 0x080CBF04
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CBF50
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080CBF48 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080CBF4C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080CBF5A
	.align 2, 0
_080CBF48: .4byte 0xFFFF0000
_080CBF4C: .4byte 0x0000FFFF
_080CBF50:
	ldr r1, _080CBF88 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080CBF5A:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CBF82
	cmp r1, #0
	blt _080CBF82
	ldr r0, _080CBF8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CBF82
	ldr r0, _080CBF90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CBF94
_080CBF82:
	movs r4, #0
	b _080CBFA2
	.align 2, 0
_080CBF88: .4byte 0xFFFF0000
_080CBF8C: .4byte 0x030046A8
_080CBF90: .4byte 0x030046AC
_080CBF94:
	ldr r0, _080CBFB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CBFA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CBFB8
	adds r0, #4
	b _080CBFC4
	.align 2, 0
_080CBFB4: .4byte 0x030046A4
_080CBFB8:
	ldr r0, _080CBFD8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CBFC4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CBFDC
	cmp r2, #2
	beq _080CBFE0
	b _080CBFE4
	.align 2, 0
_080CBFD8: .4byte 0x030046A4
_080CBFDC:
	ldrb r0, [r5, #4]
	b _080CBFE2
_080CBFE0:
	ldrb r0, [r5]
_080CBFE2:
	subs r1, r1, r0
_080CBFE4:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x18]
	movs r2, #7
	str r2, [sp]
	str r6, [sp, #4]
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cc004
FUN_080cc004: @ 0x080CC004
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xa8
	adds r1, r5, #0
	adds r1, #0x24
	adds r0, r4, #0
	bl FUN_0823280c
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc02c
FUN_080cc02c: @ 0x080CC02C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x8c
	ldr r1, _080CC090 @ =0x00009247
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r5, #0
	bl FUN_0823b46c
	ldr r1, _080CC094 @ =0x00000133
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080CC098 @ =0x0000922E
	ldr r1, _080CC09C @ =0x00001DF8
	bl GetFile
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #7
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080cbd94
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC090: .4byte 0x00009247
_080CC094: .4byte 0x00000133
_080CC098: .4byte 0x0000922E
_080CC09C: .4byte 0x00001DF8

	thumb_func_start FUN_080cc0a0
FUN_080cc0a0: @ 0x080CC0A0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xb8
	ldr r2, _080CC10C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _080CC110 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080CC114 @ =0x00002001
	movs r4, #0x10
	str r4, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x1e
	movs r3, #0
	bl FUN_082364f8
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC10C: .4byte 0xFFFF0000
_080CC110: .4byte 0x0000FFFF
_080CC114: .4byte 0x00002001

	thumb_func_start EntityF41A_Init
EntityF41A_Init: @ 0x080CC118
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_080cbf04
	adds r0, r4, #0
	bl FUN_080cc004
	adds r0, r4, #0
	bl FUN_080cc02c
	adds r0, r4, #0
	bl FUN_080cc0a0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x1c
	ldr r2, _080CC154 @ =FUN_080cbb68
	bl Entity5941_Register
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cbb2c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080CC154: .4byte FUN_080cbb68

	thumb_func_start EntityF41A_Create
EntityF41A_Create: @ 0x080CC158
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CC198
	ldr r1, _080CC190 @ =EntityF41A_Update
	ldr r2, _080CC194 @ =EntityF41A_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityF41A_Init
	cmp r0, #0
	bge _080CC198
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CC19A
	.align 2, 0
_080CC190: .4byte EntityF41A_Update
_080CC194: .4byte EntityF41A_Destroy
_080CC198:
	adds r0, r4, #0
_080CC19A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
