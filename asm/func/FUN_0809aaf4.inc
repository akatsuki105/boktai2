	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809AB2C @ =0x000009EC
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #1
	bne _0809AB06
	bl FUN_082407e0
_0809AB06:
	ldrh r0, [r4]
	cmp r0, #2
	bne _0809AB14
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809AB14:
	ldrh r0, [r4]
	cmp r0, #0xf
	bhi _0809AB34
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	ldr r1, _0809AB30 @ =0x00001084
	bl FUN_0808a458
	b _0809AB3C
	.align 2, 0
_0809AB2C: .4byte 0x000009EC
_0809AB30: .4byte 0x00001084
_0809AB34:
	ldr r1, _0809AB64 @ =0x00001084
	movs r0, #0
	bl FUN_0808a458
_0809AB3C:
	ldr r0, _0809AB68 @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x12
	bls _0809AB5C
	adds r0, r5, #0
	bl FUN_0809a6a8
	ldr r1, _0809AB6C @ =FUN_0809ab70
	adds r0, r5, #0
	bl FUN_0808a33c
_0809AB5C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AB64: .4byte 0x00001084
_0809AB68: .4byte 0x000009EC
_0809AB6C: .4byte FUN_0809ab70
