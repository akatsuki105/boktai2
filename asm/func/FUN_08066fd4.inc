	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0806701C @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08066FF0
	ldr r2, _08067020 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _08066FF0
	movs r1, #1
_08066FF0:
	cmp r1, #0
	bne _08067018
	ldr r1, _08067024 @ =0x00000362
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, #0x64
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	cmp r1, #0x10
	ble _08067028
_08067018:
	movs r1, #0x10
	b _0806702E
	.align 2, 0
_0806701C: .4byte 0x00000446
_08067020: .4byte 0x00000442
_08067024: .4byte 0x00000362
_08067028:
	cmp r1, #8
	bgt _0806702E
	movs r1, #9
_0806702E:
	ldr r2, _08067058 @ =0x000004C5
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08067044
	adds r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08067044
	subs r1, #4
_08067044:
	ldr r0, _0806705C @ =0x00000402
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08067050
	subs r1, r1, r0
_08067050:
	cmp r1, #1
	ble _08067060
	adds r0, r1, #0
	b _08067062
	.align 2, 0
_08067058: .4byte 0x000004C5
_0806705C: .4byte 0x00000402
_08067060:
	movs r0, #2
_08067062:
	pop {r4}
	pop {r1}
	bx r1
