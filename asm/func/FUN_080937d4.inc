	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, _08093884 @ =0x00003AEE
	adds r4, r6, r0
	ldrb r0, [r4]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08093888 @ =0x00000F6C
	adds r2, r6, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r7, #1
	orrs r0, r7
	str r0, [r2]
	ldrb r1, [r4]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r5, sp, #0x18
	ldr r1, _0809388C @ =0x00003AEB
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_080921e8
	ldr r1, _08093890 @ =0x00003F9C
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r1, [r4]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r4]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, _08093894 @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0808c334
	ldr r0, _08093898 @ =0x0000038A
	bl PlaySound_082406e0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809387C
	ldr r2, _0809389C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080938A0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080938A4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, #0x13
	bgt _080938AC
_0809387C:
	ldr r1, _080938A8 @ =0x00003F9D
	adds r0, r6, r1
	strb r7, [r0]
	b _080938B4
	.align 2, 0
_08093884: .4byte 0x00003AEE
_08093888: .4byte 0x00000F6C
_0809388C: .4byte 0x00003AEB
_08093890: .4byte 0x00003F9C
_08093894: .4byte 0x00000F9E
_08093898: .4byte 0x0000038A
_0809389C: .4byte 0x030046B8
_080938A0: .4byte 0x000003FF
_080938A4: .4byte 0x0203B400
_080938A8: .4byte 0x00003F9D
_080938AC:
	ldr r0, _080938C8 @ =0x00003F9D
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
_080938B4:
	ldr r1, _080938CC @ =FUN_080938d0
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080938C8: .4byte 0x00003F9D
_080938CC: .4byte FUN_080938d0
