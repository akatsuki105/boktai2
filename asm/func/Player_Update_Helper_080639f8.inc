	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r2, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _08063A34
	adds r0, r5, #0
	bl FUN_08063814
	adds r0, r5, #0
	bl FUN_080639d0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08063668
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_08063498
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_080637dc
	adds r2, r0, #0
	b _08063A50
_08063A34:
	ldr r1, _08063A60 @ =0x0000038E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _08063A64 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r6, #0xb2
	lsls r6, r6, #2
	adds r0, r0, r6
	ldr r0, [r0]
	cmp r0, #0
	ble _08063A50
	movs r2, #6
_08063A50:
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _08063A68
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_080628ec
	b _08063A70
	.align 2, 0
_08063A60: .4byte 0x0000038E
_08063A64: .4byte 0x030046A0
_08063A68:
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_08062688
_08063A70:
	adds r0, r5, #0
	bl FUN_08061384
	adds r0, r5, #0
	bl FUN_080614bc
	adds r0, r5, #0
	bl FUN_08061c68
	adds r0, r5, #0
	bl FUN_08061e2c
	ldr r0, _08063B08 @ =0x00000714
	adds r1, r5, r0
	ldr r2, _08063B0C @ =0x000006AC
	adds r0, r5, r2
	ldr r1, [r1]
	bl _call_via_r1
	ldr r6, _08063B10 @ =0x00000992
	adds r1, r5, r6
	ldrh r0, [r1]
	cmp r0, #0
	beq _08063ACE
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08063ACE
	ldr r0, _08063B14 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	subs r6, #2
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
_08063ACE:
	ldr r1, _08063B18 @ =0x00000604
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2c]
	adds r0, r0, r2
	ldr r6, _08063B1C @ =0x000005FC
	adds r1, r5, r6
	strh r0, [r1]
	ldr r1, _08063B20 @ =0x00000606
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	adds r6, #2
	adds r1, r5, r6
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x30]
	adds r0, r0, r2
	adds r6, #2
	adds r1, r5, r6
	strh r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08063B08: .4byte 0x00000714
_08063B0C: .4byte 0x000006AC
_08063B10: .4byte 0x00000992
_08063B14: .4byte 0x0000098C
_08063B18: .4byte 0x00000604
_08063B1C: .4byte 0x000005FC
_08063B20: .4byte 0x00000606
