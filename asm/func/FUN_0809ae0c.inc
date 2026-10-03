	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809AE2C @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0809AE34
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	ldr r1, _0809AE30 @ =0x00001084
	bl FUN_0808a458
	b _0809AE3C
	.align 2, 0
_0809AE2C: .4byte 0x000009EC
_0809AE30: .4byte 0x00001084
_0809AE34:
	ldr r1, _0809AE78 @ =0x00001084
	movs r0, #0
	bl FUN_0808a458
_0809AE3C:
	ldr r2, _0809AE7C @ =0x000009EC
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0xf
	bne _0809AE52
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
_0809AE52:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x12
	bls _0809AE9C
	ldr r0, _0809AE80 @ =0x0000401D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809AE84
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_0808f95c
	b _0809AE9C
	.align 2, 0
_0809AE78: .4byte 0x00001084
_0809AE7C: .4byte 0x000009EC
_0809AE80: .4byte 0x0000401D
_0809AE84:
	adds r0, r5, #0
	bl FUN_0809a81c
	ldr r1, _0809AEA4 @ =0x03004460
	ldr r2, _0809AEA8 @ =0x000009B2
	adds r0, r5, r2
	ldrh r0, [r0]
	str r0, [r1]
	ldr r1, _0809AEAC @ =FUN_0809aeb0
	adds r0, r5, #0
	bl FUN_0808a33c
_0809AE9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AEA4: .4byte 0x03004460
_0809AEA8: .4byte 0x000009B2
_0809AEAC: .4byte FUN_0809aeb0
