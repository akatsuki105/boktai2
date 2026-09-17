	push {r4, r5, r6, lr}
	sub sp, #0x10
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r4, _0823CF18 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	str r0, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823CF14
	cmp r1, #0
	blt _0823CF14
	ldr r0, _0823CF1C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823CF14
	ldr r0, _0823CF20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823CF24
_0823CF14:
	movs r4, #0
	b _0823CF32
	.align 2, 0
_0823CF18: .4byte 0xFFFF0000
_0823CF1C: .4byte 0x030046A8
_0823CF20: .4byte 0x030046AC
_0823CF24:
	ldr r0, _0823CF44 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823CF32:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823CF48
	adds r0, #4
	b _0823CF54
	.align 2, 0
_0823CF44: .4byte 0x030046A4
_0823CF48:
	ldr r0, _0823CF68 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823CF54:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r5, r0, #8
	cmp r2, #1
	beq _0823CF6C
	cmp r2, #2
	beq _0823CF70
	b _0823CF74
	.align 2, 0
_0823CF68: .4byte 0x030046A4
_0823CF6C:
	ldrb r0, [r6, #4]
	b _0823CF72
_0823CF70:
	ldrb r0, [r6]
_0823CF72:
	subs r5, r5, r0
_0823CF74:
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	adds r0, r5, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
