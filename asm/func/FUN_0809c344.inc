	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _0809C368 @ =0x0300013C
	ldr r2, [r0]
	cmp r2, #0
	beq _0809C3B4
	ldr r1, _0809C36C @ =0x000009FE
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _0809C3B4
	cmp r4, #0
	bge _0809C374
	ldr r4, _0809C370 @ =0x00000A06
	adds r0, r2, r4
	strh r1, [r0]
	b _0809C37A
	.align 2, 0
_0809C368: .4byte 0x0300013C
_0809C36C: .4byte 0x000009FE
_0809C370: .4byte 0x00000A06
_0809C374:
	ldr r1, _0809C39C @ =0x00000A06
	adds r0, r2, r1
	strh r4, [r0]
_0809C37A:
	ldr r4, _0809C3A0 @ =0x00000A08
	adds r0, r2, r4
	strh r5, [r0]
	ldr r1, _0809C3A4 @ =0x00000A0C
	adds r0, r2, r1
	strb r3, [r0]
	adds r4, #2
	adds r1, r2, r4
	movs r0, #0xb4
	strh r0, [r1]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq _0809C3AC
	ldr r0, _0809C3A8 @ =0x00000A0D
	adds r1, r2, r0
	movs r0, #6
	b _0809C3B2
	.align 2, 0
_0809C39C: .4byte 0x00000A06
_0809C3A0: .4byte 0x00000A08
_0809C3A4: .4byte 0x00000A0C
_0809C3A8: .4byte 0x00000A0D
_0809C3AC:
	ldr r4, _0809C3BC @ =0x00000A0D
	adds r1, r2, r4
	movs r0, #0
_0809C3B2:
	strb r0, [r1]
_0809C3B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C3BC: .4byte 0x00000A0D
