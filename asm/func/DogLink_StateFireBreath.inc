	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _081C9B7C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9B80
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9B82
	.align 2, 0
_081C9B7C: .4byte 0x0000046D
_081C9B80:
	movs r0, #0
_081C9B82:
	cmp r0, #0
	beq _081C9BA0
	adds r0, r4, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	adds r0, r4, #0
	adds r0, #8
	ldrb r1, [r4, #5]
	movs r2, #0
	bl Entity081f1770_Spawn
	ldr r0, _081C9BCC @ =0x000003A5
	bl PlaySound_082406e0
_081C9BA0:
	adds r0, r5, #0
	subs r0, #0xd
	cmp r0, #0xa
	bhi _081C9BB2
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl Hitbox_Register
_081C9BB2:
	ldr r1, _081C9BD0 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C9BC4
	ldr r0, _081C9BD4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081C9BC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081C9BCC: .4byte 0x000003A5
_081C9BD0: .4byte 0x0000046E
_081C9BD4: .4byte 0x0000046B
