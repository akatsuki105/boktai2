	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xae
	lsls r1, r1, #4
	adds r0, r6, r1
	bl AuxSprite_Remove
	ldr r1, _0819A094 @ =0x00000B28
	adds r0, r6, r1
	bl AuxShadow_Remove
	ldr r1, _0819A098 @ =0x00000B94
	adds r0, r6, r1
	bl Hitbox_Unregister
	ldr r1, _0819A09C @ =0x00000BE4
	adds r0, r6, r1
	bl Hitbox_Unregister
	adds r4, r6, #0
	adds r4, #0x60
	movs r0, #3
	mov r8, r0
_0819A02E:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r0, r8
	cmp r0, #0
	bge _0819A02E
	movs r1, #0
	mov r8, r1
	ldr r1, _0819A0A0 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0819A086
	ldr r0, _0819A0A4 @ =0x000004EC
	adds r7, r6, r0
	ldr r1, _0819A0A8 @ =0x0000049C
	adds r5, r6, r1
	subs r0, #0x98
	adds r4, r6, r0
_0819A05C:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	bl Hitbox_Unregister
	adds r0, r7, #0
	bl Hitbox_Unregister
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r5, r5, r1
	adds r4, r4, r1
	movs r0, #1
	add r8, r0
	ldr r1, _0819A0A0 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r8, r0
	blt _0819A05C
_0819A086:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0819A094: .4byte 0x00000B28
_0819A098: .4byte 0x00000B94
_0819A09C: .4byte 0x00000BE4
_0819A0A0: .4byte 0x00000C9C
_0819A0A4: .4byte 0x000004EC
_0819A0A8: .4byte 0x0000049C
