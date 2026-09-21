	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018E68
	ldrb r0, [r4, #0x18]
	cmp r0, #3
	bhi _08018E2C
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _08018DFE
	ldr r2, _08018E24 @ =0x030042AE
	adds r1, r2, #0
	subs r1, #8
_08018DF0:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r1, #2
	adds r3, #1
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	blt _08018DF0
_08018DFE:
	cmp r3, #3
	bgt _08018E68
	ldr r0, _08018E28 @ =0x03004330
	lsls r1, r3, #1
	rsbs r1, r1, #0
	adds r2, r1, #0
	subs r2, #0x8a
	adds r2, r2, r0
	adds r1, #8
	adds r1, r1, r0
_08018E12:
	ldrh r0, [r1]
	strh r0, [r2]
	subs r2, #2
	subs r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08018E12
	b _08018E68
	.align 2, 0
_08018E24: .4byte 0x030042AE
_08018E28: .4byte 0x03004330
_08018E2C:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	subs r0, #4
	cmp r3, r0
	bge _08018E50
	ldr r0, _08018E98 @ =0x03004332
	adds r2, r0, #0
	subs r2, #0x92
	adds r1, r0, #0
_08018E3E:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	ldrb r0, [r4, #0x18]
	subs r0, #4
	cmp r3, r0
	blt _08018E3E
_08018E50:
	cmp r3, #3
	bgt _08018E68
	ldr r2, _08018E9C @ =0x030042AE
	lsls r0, r3, #1
	subs r0, #0xe
	adds r1, r0, r2
_08018E5C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08018E5C
_08018E68:
	ldrb r0, [r4, #0x19]
	adds r0, #1
	strb r0, [r4, #0x19]
	ldr r1, _08018EA0 @ =0x085AA95C
	ldrb r2, [r4, #0x18]
	adds r1, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08018ECA
	cmp r2, #3
	bhi _08018EA4
	movs r0, #0xb
	subs r1, r0, r2
	ldr r2, _08018E9C @ =0x030042AE
	lsls r0, r1, #1
	adds r1, r2, #0
	subs r1, #0x1e
	adds r0, r0, r1
	ldrh r1, [r2]
	strh r1, [r0]
	b _08018EB6
	.align 2, 0
_08018E98: .4byte 0x03004332
_08018E9C: .4byte 0x030042AE
_08018EA0: .4byte 0x085AA95C
_08018EA4:
	adds r1, r2, #4
	lsls r2, r2, #1
	ldr r0, _08018ED4 @ =0x0300432A
	adds r2, r2, r0
	lsls r1, r1, #1
	subs r0, #0x9a
	adds r1, r1, r0
	ldrh r0, [r2]
	strh r0, [r1]
_08018EB6:
	ldrb r0, [r4, #0x18]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08018EC8
	strb r1, [r4, #0x18]
_08018EC8:
	strb r1, [r4, #0x19]
_08018ECA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08018ED4: .4byte 0x0300432A
