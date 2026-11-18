	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197B02
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197B04
_08197B02:
	movs r0, #0
_08197B04:
	cmp r0, #0
	beq _08197BE4
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08197C04 @ =0x00000B9A
	adds r2, r4, r1
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08197C08 @ =0x00000BEA
	adds r2, r4, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	movs r7, #0
	movs r1, #0x60
	adds r1, r1, r4
	mov sl, r1
	ldr r2, _08197C0C @ =0x00000AFC
	adds r2, r2, r4
	mov r8, r2
	ldr r0, _08197C10 @ =0x000002C6
	adds r6, r4, r0
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r5, r4, r1
	movs r2, #4
	mov sb, r2
_08197B48:
	movs r0, #0x2c
	adds r2, r7, #0
	muls r2, r0, r2
	adds r3, r4, r2
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x7c
	strh r1, [r0]
	ldr r1, _08197C14 @ =0x00000AFE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x7e
	strh r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x80
	strh r1, [r0]
	ldr r1, _08197C18 @ =0x00000AE6
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x66
	strb r1, [r0]
	add r2, sl
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrh r0, [r5]
	mov r2, sb
	orrs r0, r2
	strh r0, [r5]
	ldrh r0, [r6]
	orrs r0, r2
	strh r0, [r6]
	mov r0, r8
	bl Map_GetTileHeightAt
	movs r2, #0xc7
	lsls r2, r2, #4
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1]
	adds r6, #0x50
	adds r5, #0x50
	adds r7, #1
	cmp r7, #3
	ble _08197B48
	movs r2, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x20]
	ldr r0, _08197C1C @ =0x0000FFF9
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x28]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _08197C20 @ =FUN_08196dfc
	str r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _08197C24 @ =FUN_081958b4
	str r0, [r1]
	ldr r1, _08197C28 @ =0x00000CC3
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _08197C2C @ =0x0000016F
	bl PlaySound_082406e0
_08197BE4:
	movs r2, #0xc5
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08197BF6
	adds r0, r4, #0
	bl _call_via_r1
_08197BF6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197C04: .4byte 0x00000B9A
_08197C08: .4byte 0x00000BEA
_08197C0C: .4byte 0x00000AFC
_08197C10: .4byte 0x000002C6
_08197C14: .4byte 0x00000AFE
_08197C18: .4byte 0x00000AE6
_08197C1C: .4byte 0x0000FFF9
_08197C20: .4byte FUN_08196dfc
_08197C24: .4byte FUN_081958b4
_08197C28: .4byte 0x00000CC3
_08197C2C: .4byte 0x0000016F
