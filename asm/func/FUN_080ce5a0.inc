	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r1, #0
	ldr r2, _080CE5EC @ =0x00000A9C
	adds r0, r3, r2
	movs r5, #2
_080CE5AE:
	str r1, [r0]
	str r1, [r0, #0xc]
	str r1, [r0, #0x18]
	adds r0, #4
	subs r5, #1
	cmp r5, #0
	bge _080CE5AE
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0x10
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	movs r5, #0
	adds r4, r0, #0
_080CE5D0:
	lsls r0, r5, #2
	adds r1, r6, r0
	ldrb r1, [r1, #0x18]
	subs r1, #1
	adds r2, r0, #0
	cmp r1, #0x1e
	bls _080CE5E0
	b _080CE858
_080CE5E0:
	lsls r0, r1, #2
	ldr r1, _080CE5F0 @ =_080CE5F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CE5EC: .4byte 0x00000A9C
_080CE5F0: .4byte _080CE5F4
_080CE5F4: @ jump table
	.4byte _080CE670 @ case 0
	.4byte _080CE698 @ case 1
	.4byte _080CE710 @ case 2
	.4byte _080CE724 @ case 3
	.4byte _080CE858 @ case 4
	.4byte _080CE858 @ case 5
	.4byte _080CE858 @ case 6
	.4byte _080CE6C0 @ case 7
	.4byte _080CE6D4 @ case 8
	.4byte _080CE6AC @ case 9
	.4byte _080CE6FC @ case 10
	.4byte _080CE6E8 @ case 11
	.4byte _080CE684 @ case 12
	.4byte _080CE670 @ case 13
	.4byte _080CE698 @ case 14
	.4byte _080CE74C @ case 15
	.4byte _080CE738 @ case 16
	.4byte _080CE7C4 @ case 17
	.4byte _080CE7D8 @ case 18
	.4byte _080CE7EC @ case 19
	.4byte _080CE800 @ case 20
	.4byte _080CE760 @ case 21
	.4byte _080CE774 @ case 22
	.4byte _080CE788 @ case 23
	.4byte _080CE79C @ case 24
	.4byte _080CE7B0 @ case 25
	.4byte _080CE814 @ case 26
	.4byte _080CE828 @ case 27
	.4byte _080CE850 @ case 28
	.4byte _080CE846 @ case 29
	.4byte _080CE83C @ case 30
_080CE670:
	ldr r1, _080CE67C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE680 @ =FUN_080ce4d0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE67C: .4byte 0x00000A9C
_080CE680: .4byte FUN_080ce4d0
_080CE684:
	ldr r1, _080CE690 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE694 @ =Player_WeaponEffectStatCond
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE690: .4byte 0x00000A9C
_080CE694: .4byte Player_WeaponEffectStatCond
_080CE698:
	ldr r1, _080CE6A4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6A8 @ =FUN_080ce4f0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6A4: .4byte 0x00000A9C
_080CE6A8: .4byte FUN_080ce4f0
_080CE6AC:
	ldr r1, _080CE6B8 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6BC @ =Player_WeaponEffectAgility
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6B8: .4byte 0x00000A9C
_080CE6BC: .4byte Player_WeaponEffectAgility
_080CE6C0:
	ldr r1, _080CE6CC @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6D0 @ =Player_WeaponEffectVitality
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6CC: .4byte 0x00000A9C
_080CE6D0: .4byte Player_WeaponEffectVitality
_080CE6D4:
	ldr r1, _080CE6E0 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6E4 @ =Player_WeaponEffectSpirit
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6E0: .4byte 0x00000A9C
_080CE6E4: .4byte Player_WeaponEffectSpirit
_080CE6E8:
	ldr r1, _080CE6F4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6F8 @ =Player_WeaponEffectENE
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6F4: .4byte 0x00000A9C
_080CE6F8: .4byte Player_WeaponEffectENE
_080CE6FC:
	ldr r1, _080CE708 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE70C @ =Player_WeaponEffectHP
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE708: .4byte 0x00000A9C
_080CE70C: .4byte Player_WeaponEffectHP
_080CE710:
	ldr r1, _080CE71C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE720 @ =Player_WeaponEffectKajiba
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE71C: .4byte 0x00000A9C
_080CE720: .4byte Player_WeaponEffectKajiba
_080CE724:
	ldr r1, _080CE730 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE734 @ =Player_WeaponEffectGyakuKajiba
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE730: .4byte 0x00000A9C
_080CE734: .4byte Player_WeaponEffectGyakuKajiba
_080CE738:
	ldr r1, _080CE744 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE748 @ =FUN_080ce504
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE744: .4byte 0x00000AB4
_080CE748: .4byte FUN_080ce504
_080CE74C:
	ldr r1, _080CE758 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE75C @ =Player_WeaponEffectRandom
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE758: .4byte 0x00000AB4
_080CE75C: .4byte Player_WeaponEffectRandom
_080CE760:
	ldr r1, _080CE76C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE770 @ =Player_WeaponEffectAntiBeast
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE76C: .4byte 0x00000AB4
_080CE770: .4byte Player_WeaponEffectAntiBeast
_080CE774:
	ldr r1, _080CE780 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE784 @ =Player_WeaponEffectAntiThing
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE780: .4byte 0x00000AB4
_080CE784: .4byte Player_WeaponEffectAntiThing
_080CE788:
	ldr r1, _080CE794 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE798 @ =Player_WeaponEffectAntiPhantom
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE794: .4byte 0x00000AB4
_080CE798: .4byte Player_WeaponEffectAntiPhantom
_080CE79C:
	ldr r1, _080CE7A8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7AC @ =Player_WeaponEffectAntiUndead
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7A8: .4byte 0x00000AB4
_080CE7AC: .4byte Player_WeaponEffectAntiUndead
_080CE7B0:
	ldr r1, _080CE7BC @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7C0 @ =Player_WeaponEffectAntiImmortal
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7BC: .4byte 0x00000AB4
_080CE7C0: .4byte Player_WeaponEffectAntiImmortal
_080CE7C4:
	ldr r1, _080CE7D0 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7D4 @ =Player_WeaponEffectFlame
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7D0: .4byte 0x00000AB4
_080CE7D4: .4byte Player_WeaponEffectFlame
_080CE7D8:
	ldr r1, _080CE7E4 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7E8 @ =Player_WeaponEffectFrost
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7E4: .4byte 0x00000AB4
_080CE7E8: .4byte Player_WeaponEffectFrost
_080CE7EC:
	ldr r1, _080CE7F8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7FC @ =Player_WeaponEffectCloud
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7F8: .4byte 0x00000AB4
_080CE7FC: .4byte Player_WeaponEffectCloud
_080CE800:
	ldr r1, _080CE80C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE810 @ =Player_WeaponEffectEarth
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE80C: .4byte 0x00000AB4
_080CE810: .4byte Player_WeaponEffectEarth
_080CE814:
	ldr r1, _080CE820 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE824 @ =CheckNamakuraProc
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE820: .4byte 0x00000AA8
_080CE824: .4byte CheckNamakuraProc
_080CE828:
	ldr r1, _080CE834 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE838 @ =CheckParalyzeProc
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE834: .4byte 0x00000AA8
_080CE838: .4byte CheckParalyzeProc
_080CE83C:
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	b _080CE856
_080CE846:
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	b _080CE856
_080CE850:
	movs r1, #4
	ldr r0, [r4]
	orrs r0, r1
_080CE856:
	str r0, [r4]
_080CE858:
	adds r5, #1
	cmp r5, #2
	bgt _080CE860
	b _080CE5D0
_080CE860:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
