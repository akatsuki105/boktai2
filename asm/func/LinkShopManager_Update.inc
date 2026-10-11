	push {r4, lr}
	adds r4, r0, #0
	bl Taiyo_Disable
	ldr r1, _081E210C @ =0x0300481C
	movs r0, #1
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2110
	movs r0, #1
	b _081E2112
	.align 2, 0
_081E210C: .4byte 0x0300481C
_081E2110:
	movs r0, #0
_081E2112:
	cmp r0, #0
	bne _081E211C
	ldr r1, _081E2130 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081E211C:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E2134
	movs r0, #1
	b _081E2136
	.align 2, 0
_081E2130: .4byte 0x030047B8
_081E2134:
	movs r0, #0
_081E2136:
	cmp r0, #0
	beq _081E2148
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21A6
	adds r0, r4, #0
	bl _call_via_r1
	b _081E21A6
_081E2148:
	ldr r1, _081E215C @ =0x030047B8
	movs r0, #1
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081E2160
	movs r0, #1
	b _081E2162
	.align 2, 0
_081E215C: .4byte 0x030047B8
_081E2160:
	movs r0, #0
_081E2162:
	cmp r0, #0
	beq _081E21B0
	bl FUN_0823849c
	adds r0, r4, #0
	bl LinkShopManager_CheckLinkLost
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E21B0
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r2, _081E21AC @ =LinkShopManager_StateError
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	bl Sio_Stop
_081E21A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E21BE
	.align 2, 0
_081E21AC: .4byte LinkShopManager_StateError
_081E21B0:
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21BC
	adds r0, r4, #0
	bl _call_via_r1
_081E21BC:
	movs r0, #1
_081E21BE:
	pop {r4}
	pop {r1}
	bx r1
